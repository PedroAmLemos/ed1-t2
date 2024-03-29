#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reading.h"
#include "reading_utility.h"
#include "arq_treat.h"


void read(char *entryPath, char *geo, char *qry, char *outPath){
	char *outPathGEO = NULL; //out path + geo name

	/* ---GEO--- */
	char *geoName = NULL; // only geo name
	char *geoPath = NULL; // path to geo							   ---> arquivo de entrada
	char *geoSVG  = NULL; // out path + geo name + svg				   ---> arquivo de saida
	FILE *geoFile = NULL;
	FILE *geoSVGFile = NULL;

	/* ---QRY--- */
	char *qryName = NULL; // only qry name
	char *qryPath = NULL; // path to qry							   ---> arquivo de entrada
	char *qrySVG  = NULL; // out path + geo name + - + qry name + .svg ---> arquivo de saida
	char *qryTXT  = NULL; // same as qry svg but .txt				   ---> arquivo de saida
	FILE *qryFile = NULL;
	FILE *qrySVGFile = NULL;
	FILE *qryTXTFile = NULL;


	/* ---Preparing files for reading---*/
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
	geoFile = fopen(geoPath, "r"); // abrindo o arquivo .geo
	outPathGEO = concat_path_file(outPath, geoName); // outpath + geo_name

	/* ---File creation---*/
	// GEO SVG == OUT PATH/GEOFILE NAME.svg
	geoSVG = malloc(sizeof(char*)*(strlen(outPathGEO)+5));
	strcpy(geoSVG, outPathGEO);
	strcat(geoSVG, ".svg");
	geoSVGFile = fopen(geoSVG, "w"); // mudar para uma funcao que cria tag

	if(qryPath){
		qryFile = fopen(qryPath, "r");
		// QRY SVG == OUTPATHGEO + '-' + QRYNAME . SVG
		// QRY TXT == OUTPATHGEO + '-' + QRYNAME . TXT
		qrySVG = malloc(sizeof(char*)*(strlen(outPathGEO)+strlen(qryName)+6));
		qryTXT = malloc(sizeof(char*)*(strlen(outPathGEO)+strlen(qryName)+6));
		strcpy(qrySVG, outPathGEO);
		strcat(qrySVG, "-");
		strcat(qrySVG, qryName);
		strcpy(qryTXT, qrySVG);
		strcat(qrySVG, ".svg");
		strcat(qryTXT, ".txt");
		qrySVGFile = fopen(qrySVG, "w"); // mudar para uma funcao que cria tag
		qryTXTFile = fopen(qryTXT, "w");
	}

	main_treatment(geoFile, qryFile, geoSVGFile, qrySVGFile, qryTXTFile);

	/* ---Free mallocs and closing files--*/
	free(geoName);
	free(geoPath);
	free(outPathGEO);
	free(geoSVG);
	fclose(geoFile);
	fclose(geoSVGFile);

	if(qryPath){
		free(qryName);
		free(qryPath);
		free(qrySVG);
		free(qryTXT);
		fclose(qryFile);
		fclose(qrySVGFile);
		fclose(qryTXTFile);
	}
}
