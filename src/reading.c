#include "reading.h"
#include "reading_utility.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read(char *entryPath, char *geo, char *qry, char *outPath){
	/* ---GEO--- */
	char *geoName = NULL; 
	char *geoPath = NULL;
	char *geoSVG  = NULL;

	/* ---QRY--- */
	char *qryName = NULL;
	char *qryPath = NULL;
	char *qrySVG  = NULL;
	char *qryTXT  = NULL;
	if(entryPath){
		if(qry != NULL){
			qryPath = concat_path_file(entryPath, qry);
			qryName = copy_file_name(qry);
		}
		geoPath = concat_path_file(entryPath, geo);
		geoName = copy_file_name(geo);
	}else{
		if(qry != NULL){
			qryPath = copy(qry);
			qryName = copy_file_name(qry);
		}
		geoPath = copy(geo);
		geoName = copy_file_name(geo);
	}
	printf("%s %s %s %s\n", geoPath, qryPath, geoName, qryName);
	free(geoName);
	free(geoPath);
	if(qryName)
		free(qryName);
	if(qryPath)
		free(qryPath);
	
}

