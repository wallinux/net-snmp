
/*
 * Note: this file originally auto-generated by mib2c using
 *        : mib2c.access_functions.conf,v 1.3 2003/05/31 00:11:57 hardaker Exp $
 */

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "netSnmpHostsTable_access.h"
#include "netSnmpHostsTable_enums.h"
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>

#define MAX_HOSTS_LINE 4096

/* XXX: make .conf token */
#define HOSTS_FILE "/etc/hosts"

typedef struct my_loop_info_s {
   FILE *filep;
   in_addr_t theaddr;
   char line[MAX_HOSTS_LINE];
   char hostname[64];
   int lineno;
   char *current_ptr;
} my_loop_info;

typedef struct my_data_info_s {
   in_addr_t theaddr;
   in_addr_t theoldaddr;
   char hostname[64];
   int lineno;
} my_data_info;   

/** NOTE:
 * - these get_ routines MUST return data that will not be freed (ie,
 *   use static variables or persistent data).  It will be copied, if
 *   needed, immediately after the get_ routine has been called.
 * - these SET routines must copy the incoming data and can not take
 *   ownership of the memory passed in by the val pointer.
 */


/** returns the first data point within the netSnmpHostsTable table data.

    Set the my_loop_context variable to the first data point structure
    of your choice (from which you can find the next one).  This could
    be anything from the first node in a linked list, to an integer
    pointer containing the beginning of an array variable.

    Set the my_data_context variable to something to be returned to
    you later that will provide you with the data to return in a given
    row.  This could be the same pointer as what my_loop_context is
    set to, or something different.

    The put_index_data variable contains a list of snmp variable
    bindings, one for each index in your table.  Set the values of
    each appropriately according to the data matching the first row
    and return the put_index_data variable at the end of the function.
*/
netsnmp_variable_list *
netSnmpHostsTable_get_first_data_point(void **my_loop_context,
                                       void **my_data_context,
                                       netsnmp_variable_list *
                                       put_index_data,
                                       netsnmp_iterator_info *mydata)
{
    my_loop_info *loopctx;

    loopctx = SNMP_MALLOC_TYPEDEF(my_loop_info);

    if (!loopctx)
        return NULL; /*XXX log err */

    loopctx->filep = fopen("/etc/hosts","r");

    if (!loopctx->filep) {
        free(loopctx);
        return NULL;
    }

    /* at this point, we need to get the first name and address from
       the file.  But since our get_next_data_point function does
       this, we'll use it instead of duplicating code */
    *my_loop_context = loopctx;

    return netSnmpHostsTable_get_next_data_point(my_loop_context,
                                                 my_data_context,
                                                 put_index_data,
                                                 mydata);
}

/** functionally the same as netSnmpHostsTable_get_first_data_point, but
   my_loop_context has already been set to a previous value and should
   be updated to the next in the list.  For example, if it was a
   linked list, you might want to cast it to your local data type and
   then return my_loop_context->next.  The my_data_context pointer
   should be set to something you need later and the indexes in
   put_index_data updated again. */
netsnmp_variable_list *
netSnmpHostsTable_get_next_data_point(void **my_loop_context,
                                      void **my_data_context,
                                      netsnmp_variable_list *
                                      put_index_data,
                                      netsnmp_iterator_info *mydata)
{
    my_loop_info *loopctx = *my_loop_context;
    char tmpstring[64];

    if (!loopctx)
        return NULL;

    while(loopctx->filep) {
        if (!loopctx->current_ptr) {
            if (!fgets(loopctx->line, sizeof(loopctx->line), loopctx->filep)) {
                /* we're done */
                fclose(loopctx->filep);
                loopctx->filep = NULL;
                return NULL;
            }
            loopctx->lineno++;
            loopctx->current_ptr = loopctx->line;
            loopctx->current_ptr = skip_white(loopctx->current_ptr);

            if (loopctx->current_ptr == NULL || *loopctx->current_ptr == '#') {
                loopctx->current_ptr = NULL;
                continue;
            }

            loopctx->current_ptr =
                copy_nword(loopctx->current_ptr, tmpstring, sizeof(tmpstring));
            loopctx->theaddr = inet_addr(tmpstring);

            if (!loopctx->current_ptr)
                continue;
        }

        loopctx->current_ptr =
            copy_nword(loopctx->current_ptr, loopctx->hostname, sizeof(loopctx->hostname));
        
        snmp_set_var_value(put_index_data, (u_char *) loopctx->hostname,
                           strlen(loopctx->hostname));
        return put_index_data;
    }
    
    /* we're out of data */
    *my_loop_context = NULL;
    return NULL;
}

void *
netSnmpHostsTable_context_convert_function(void *loop_context,
                                           netsnmp_iterator_info *iinfo)
{
    my_loop_info *loopctx = loop_context;
    my_data_info *datactx = SNMP_MALLOC_TYPEDEF(my_data_info);
    if (!datactx)
        return NULL;
    datactx->theoldaddr = datactx->theaddr = loopctx->theaddr;
    datactx->lineno = loopctx->lineno;
    strcpy(datactx->hostname, loopctx->hostname);
    return datactx;
}

/** Create a data_context for non-existent rows that SETs are performed on.
 *  return a void * pointer which will be passed to subsequent get_XXX
 *  and set_XXX functions for data retrival and modification during
 *  this SET request.
 *
 *  The indexs are encoded (in order) into the index_data pointer if it
 *  would be helpful to use that information.
 */
void           *
netSnmpHostsTable_create_data_context(netsnmp_variable_list * index_data)
{
    my_data_info *datactx = SNMP_MALLOC_TYPEDEF(my_data_info);
    if (!datactx)
        return NULL;
    strncpy(datactx->hostname, index_data->val.string,
            strlen(index_data->val.string));
    return datactx;
}

void
netSnmpHostsTable_data_free(void *data, netsnmp_iterator_info *iinfo)
{
    free(data);
}

void
netSnmpHostsTable_loop_free(void *loopctx, netsnmp_iterator_info *iinfo)
{
    free(loopctx);
}

/** If the implemented set_* functions don't operate directly on the
   real-live data (which is actually recommended), then this function
   can be used to take a given my_data_context pointer and "commit" it
   to whereever the modified data needs to be put back to.  For
   example, if this was a routing table you could publish the modified
   routes back into the kernel at this point.

   rowStatus will be set to 1 if new, 0 if not or -1 if it should
   be deleted.

   If you free the data yourself, make sure to *my_data_context = NULL */
int
netSnmpHostsTable_commit_row(void **my_data_context, int new_or_del)
{
    /** Add any necessary commit code here */
    FILE *in, *out;
    char line[MAX_HOSTS_LINE], line2[MAX_HOSTS_LINE];
    char myaddr[64], *cp;
    my_data_info *datactx = *my_data_context;
    size_t line2_sz;
    int foundit = 0;

    if (datactx->theaddr == datactx->theoldaddr && new_or_del != -1)
        return SNMP_ERR_NOERROR; /* no change in the value */

    if ((out = fopen(HOSTS_FILE ".snmp", "w")) == NULL)
        return SNMP_ERR_COMMITFAILED;
    
    if ((in = fopen(HOSTS_FILE, "r")) == NULL)
        return SNMP_ERR_COMMITFAILED;

    while(fgets(line, sizeof(line), in)) {
        copy_nword(line,myaddr,sizeof(myaddr));
        if (inet_addr(myaddr) == datactx->theaddr && new_or_del != -1) {
            foundit = 1;
            /* right line to append to */
            line[strlen(line)-1] = '\0'; /* nuke the new line */
            fprintf(out, "%s %s\n", line, datactx->hostname);
        } else if (inet_addr(myaddr) == datactx->theoldaddr) {
            /* find a remove the name from the current line */
            int count = 0;
            cp = copy_nword(line, line2, sizeof(line2)); /* pass the addr */
            if (strlen(line2) > sizeof(line2)-2) {
              errorit:
                fclose(in);
                fclose(out);
                unlink(HOSTS_FILE ".snmp");
                return SNMP_ERR_RESOURCEUNAVAILABLE;
            }
            line2_sz = strlen(line2);
            line2[line2_sz++] = '\t';
            while(cp) {
                cp = copy_nword(cp, &line2[line2_sz], sizeof(line2)-line2_sz);
                if (strcmp(&line2[line2_sz], datactx->hostname) == 0) {
                    /* a match, so don't add it to line2 (which means
                       don't update the write line2_sz index */
                } else {
                    if (strlen(line2) > sizeof(line2)-2) {
                        goto errorit;
                    }
                    line2_sz = strlen(line2);
                    line2[line2_sz++] = ' ';
                    count++;
                }
            }
            if (count) {
                /* at least one name was still present on the line, so
                   save it to the new file */
                line2[line2_sz] = '\0';
                fprintf(out, "%s\n", line2);
            }
        } else {
            fputs(line, out);
        }
    }

    if (!foundit && new_or_del != -1) {
        /* couldn't add it to an existing line, so append a new one */
        fprintf(out, "%d.%d.%d.%d\t%s\n",
                (0x000000ff & datactx->theaddr),
                (0x0000ff00 & datactx->theaddr) >> 8,
                (0x00ff0000 & datactx->theaddr) >> 16,
                (0xff000000 & datactx->theaddr) >> 24,
                datactx->hostname);
    }
    fclose(in);
    fclose(out);

    if (!rename(HOSTS_FILE ".snmp", HOSTS_FILE))
        return SNMP_ERR_COMMITFAILED;
        
    /*
     * return no errors.  And there shouldn't be any!!!  Ever!!!  You
     * should have checked the values long before this. 
     */
    return SNMP_ERR_NOERROR;
}


/*
 * User-defined data access functions (per column) for data in table
 * netSnmpHostsTable
 */


long           *
get_netSnmpHostAddressType(void *data_context, size_t * ret_len)
{
    static long ret = NETSNMPHOSTADDRESSTYPE_IPV4;
    *ret_len = sizeof(ret);
    return &ret;
}

int
set_netSnmpHostAddressType(void *data_context, long *val, size_t val_len)
{
    return SNMP_ERR_NOERROR; /* always ipv4 */
}

char           *
get_netSnmpHostAddress(void *data_context, size_t * ret_len)
{
    my_data_info *datainfo = data_context;
    *ret_len = sizeof(in_addr_t);  /* XXX: make sure it's 4 */
    return (char *) &datainfo->theaddr;
}

int
set_netSnmpHostAddress(void *data_context, char *val, size_t val_len)
{
    my_data_info *datainfo = data_context;
    memcpy(&datainfo->theaddr, val, val_len);
    return SNMP_ERR_NOERROR;
}

long           *
get_netSnmpHostStorage(void *data_context, size_t * ret_len)
{
    static long ret = ST_NONVOLATILE;
    *ret_len = sizeof(ret);
    return &ret;
}

int
set_netSnmpHostStorage(void *data_context, long *val, size_t val_len)
{
    return SNMP_ERR_NOERROR;
}

long           *
get_netSnmpHostRowStatus(void *data_context, size_t * ret_len)
{
    static long ret = RS_ACTIVE;
    *ret_len = sizeof(ret);
    return &ret;
}

int
set_netSnmpHostRowStatus(void *data_context, long *val, size_t val_len)
{
    /* XXX */
    return SNMP_ERR_NOERROR;
}
