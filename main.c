#include <vitasdk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replace_newline(char* str)
{
	for (int i=0; i<strlen(str); i++)
	{
		if (str[i] == '\n' || str[i] == '\r')
		{
			str[i] = 0;
		}
	}
}

int main(int argc, const char *argv[]) {
	char path[256], game_id[128];
	memset(path, 0, 256);
	memset(game_id, 0, 128);
	FILE *f = fopen("app0:path.txt", "rb");
	FILE *f2 = fopen("app0:game_id.txt", "rb");
	if (f && f2) {
		fread(path, 1, 256, f);
		fread(game_id, 1, 128, f2);
		fclose(f);
		fclose(f2);
		char uri[512];
		replace_newline(path);
		replace_newline(game_id);
		snprintf(uri, 512, "psgm:play?titleid=%s&path=%s&game_id=%s", "VSCU00001", path, game_id);
		sceAppMgrLaunchAppByUri(0xFFFFF, uri);
		sceKernelDelayThread(1000);
	}
	
	sceKernelExitProcess(0);
  
	return 0;
}
