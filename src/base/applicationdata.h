/*
 * Global data for initialization and usage
 * */
#ifndef __HEADER__applicationdata_
#define __HEADER_applicationdata_

struct application_data_param {
	char *key;
	char *value;
	struct application_data_param *next; // makes it faster to search
};

struct application_data {
	struct progmem *mem;
	struct application_data_param *params;	
};


#endif