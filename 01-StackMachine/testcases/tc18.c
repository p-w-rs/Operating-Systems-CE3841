#include <stdio.h>
#include "stackm.h"

void doPush(stackm* s, int v)
{
	printf("Push Ret: %d\n", smPush(s, v));
}

void doSub(stackm* s) 
{
	printf("Sub Ret: %d\n", smSub(s));
}

int main() {
	stackm mystack;
	smInit(&mystack);
	doSub(&mystack);
	doPush(&mystack, 10);
	doSub(&mystack);
	return 0;
}
