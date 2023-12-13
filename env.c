#include "main.h"

/**
 * create_env - Creates enviroment variables array
 * @env: store enviroment variables array
 */

void create_env(char **env)
{
	int i;

	for (i = 0; environ[i]; i++)
		env[i] = _strdup(environ[i]);
	env[i] = NULL;
}

/**
 * free_envi - frees memory of the created enviroment variables
 * @envi:  Environment variables array
 */

void free_envi(char **envi)
{
	int i;

	for (i = 0; envi[i]; i++)
	{
		free(envi[i]);
	}
}
