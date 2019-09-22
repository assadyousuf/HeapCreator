#include "util.h"

//=============================================================================

int nextCommand(int *i, int *v, int *f) {
	char c;
	while(1){
		scanf("%c", &c);
		if (c == ' ' || c == '\t' || c == '\n'){
			continue;
		}
		if (c == 'S'|| c =='s' || c == 'r' || c == 'R' || c == 'W' || c =='w'){
			break;
		}
		if (c == 'K' || c == 'k'){
            		fflush(stdin); //flush keyboard input because i kept getting an error here
			scanf("%d", f); scanf("%d", i); scanf("%d", v);
			break;
		}
        if(c == 'D' ||c == 'd'){
            scanf("%d", f);
            break;
        }
        if(c== 'I'|| c == 'i'){
            scanf("%d", f); scanf("%d", v); break;
        }
        if(c== 'C'|| c == 'c'){
            scanf("%d", i);
            break;
        }
        
        
		printf("Invalid Command\n");
	}
	return c;
}
