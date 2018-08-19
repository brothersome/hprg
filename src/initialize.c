#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base/applicationdata.h"
#include "base/memory.h"
#include "base/defaults.h"
#include "base/basemem.h"
#include "base/logging.h"
#include "base/defaults.h"
#include "base/timemanip.h"

extern struct application_data *g_application_data;

int initialize_application_data() {
	add_to_log("initializing application data");
	g_application_data = (struct application_data *)malloc(sizeof(struct application_data));
	if (g_application_data == NULL) {
		fprintf(stderr,"Problems with allocating first memory");
		return -1;
	}
	if ((g_application_data->mem = mem_create()) == NULL) {
		fprintf(stderr,"Problems with allocating first block of memory");
		return -1;
	}
	return 0;
}

int initialize_logging_startup() {
	FILE *fp;
	char tm[20];
	get_time_string(tm,0);
	char name[60];
	strcpy(name,"startup_normallog_");
	strcat(name,tm);
	strcat(name,".txt");
	fp = fopen(name,"w");
	initialize_logging_normal(fp);
	strcpy(name,"startup_errorlog_");
	strcat(name,tm);
	strcat(name,".txt");
	fp = fopen(name,"w");
	initialize_logging_error(fp);
	return 0;
}

int initialize_scheduler() {
	add_to_log("initializing scheduler");
	return 0;
}

int start_tcpip_server() {
	add_to_log("initializing tcpip server");
	return 0;
}

int initialize() {
	int ret;
	if ((ret=initialize_application_data()) < 0) return ret;
	if ((ret=initialize_logging_startup()) < 0) return ret;
	add_to_log("initializing application begin");
	if ((ret=set_defaults(g_application_data)) < 0) return ret;
	if ((ret=initialize_basemem(g_application_data)) < 0) return ret; 
	if ((ret=initialize_scheduler()) < 0) return ret;
	if ((ret=start_tcpip_server()) < 0) return ret;
	// Start tcpip server - at what port?
	add_to_log("initializing application end");
	return 0;
}

int end_intialize()
{
#ifdef TESTMODE
	add_to_log("sds",__FILE__,__LINE__,"End");
#endif
	return __LINE__;
}