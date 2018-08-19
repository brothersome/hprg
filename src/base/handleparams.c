#include "def.h"
#include "logging.h"
#include "memory.h"
#include "basemem.h"

enum Arguments {
	NOTHING=0,NORMAL,WRONG,TOO_MANY_ARGUMENTS = 10
};

void show_help(int kind) {
	switch(kind) {
	case NOTHING:
		break;
	case WRONG:
		break;
	case TOO_MANY_ARGUMENTS:
		break;
	}
}

int read_single_option_from_commandline(int kar)
{
	switch(kar)
	{
		case 'h': case 'H': case '?':
			show_help(NORMAL);
			return 0;
	}
	return 0;
}
int read_option_from_commandline(char *si)
{
	char *sArg;
	sArg = si + 1;
	if ((*sArg)=='\0')
	{
		show_help(WRONG);
		return -1;
	}
	if (sArg[1]=='\0') /* One single option */
	{
		return read_single_option_from_commandline(*sArg);
	}
	return 0;
}

int handleparams(int argc,char *argv[])
{
	int ret;
	int counter_no_opt;
	/* Options and FileIn name and FileOut name */
	int i;
	char named[12];
	strcpy(named,"cli_option");
#ifdef LOGDEBUG
	AddLog("ReadCommandLine");
#endif
	ret = 0;
	counter_no_opt = 0;
	for (i=1;i<argc;i++)
	{
		if (argv[i][0]=='-' || argv[i][0]=='/') /* This is an option */
		{
			if ((ret=read_option_from_commandline(argv[i]))<0) return ret;
		}
		else {
			// Hold this option as "named"
			named[10] = '\0';
			strcat_number(named,counter_no_opt);
			// argv[i] is hold already in memory
			
			ret++;			
		}
	}
	return ret;
}

int end_handleparams()
{
#ifdef TESTMODE
	add_to_log("sds",__FILE__,__LINE__,"End");
#endif
	return __LINE__;
}
