#include <stdio.h>
#include <config.h>
#include <unistd.h>

static void inline version(const char *prog_name) {
    printf("%s %d.%d\n", prog_name, cway_VERSION_MAJOR, cway_VERSION_MINOR);
}

void usage(const char *prog_name) {
    printf("USAGE: %s <OPTIONS>\nOPTIONS:\
	    \n  -h\tPrint this help message \
	    \n  -v\tPrint the programs version\
	    \n  -x\tSet the X display string(Only used if X backend is used)\
	    \n  -w\tSet the Wayland display(only if wayland backend is used)", prog_name);

}

int main(int argc, char **argv) {
    int opt = 0;
    
    while((opt = getopt(argc, argv, ":x:vh")) != -1) {
	switch (opt) {
	    case 'h':
		usage(argv[0]);
		return 1;
	    case 'v':
		version(argv[0]);
		return 1;
	    case 'x': 
		printf("X display string %s\n", optarg);
		break;
	    case ':':
		printf("arg -%c requires value\n", optopt);
		return 1;
	    case '?':
		printf("unrecognized arg -%c ignoring\n", optopt);
	}
    }

    return 0;
}
