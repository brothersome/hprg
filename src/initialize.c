#include <stdio.h>
#include <stdlib.h>
#include "base/applicationdata.h"
#include "base/memory.h"

extern struct application_data *g_application_data;

int initialize_application_data() {
	g_application_data = (struct application_data *)malloc(sizeof(struct application_data));
	if (g_application_data == NULL) {
		fprintf(stderr,"Problems with allocating first memory")
		return -1;
	}
	
	if ((g_application_data->mem = mem_create()) == NULL) {
		fprintf(stderr,"Problems with allocating first block of memory")
		return -1;
	}
	return 0;
}

int initialize_logging_startup() {
	FILE *fp;
	fp = fopen("startup_normallog.txt","w");
	initialize_logging_normal(fp);
	fp = fopen("startup_errorlog.txt","w");
	initialize_logging_error(fp);
}

int initialize_scheduler() {
	return 0;
}

int start_tcpip_server() {
	return 0;
}

int initialize() {
	int ret;
	if ((ret=initialize_application_data()) < 0) return ret;
	if ((ret=initialize_logging_startup()) < 0) return ret;
	if ((ret=initialize_scheduler()) < 0) return ret;
	if ((ret=start_tcpip_server()) < 0) return ret;
	// Start tcpip server - at what port?
	return 0;
}

int end_intialize()
{
#ifdef TESTMODE
	add_to_log("sds",__FILE__,__LINE__,"End");
#endif
	return __LINE__;
}