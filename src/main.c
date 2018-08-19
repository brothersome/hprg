#include <stdio.h>
#include "def.h"
#include "base/handleparams.h"
#include "initialize.h"
#include "base/applicationdata.h"
#include "base/logging.h"

struct application_data *g_application_data;

int main(int argc,char *argv[]) {
	int ret;
    if ((ret = handleparams(argc,argv)) < 0) {
		return ret * -1;
	}
	if ((ret = initialize()) < 0) {
		return ret * -1;
	}
    return 0;
}

int end_main()
{
#ifdef TESTMODE
	add_to_log("sds",__FILE__,__LINE__,"End");
#endif
	return __LINE__;
}
