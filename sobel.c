// Mani Manjusha Kottala
//Multimedia Assignment : Edge Detection


//include header files
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
		
int main()
{
	//variable declaration
	int height = 500 , width = 500 ;
	int i = 0,j = 0,total=0, x=0, y=0, ch,threshold;
	
	//variables to hold image data
	unsigned char Image_data[height][width], filter_data[height][width];
	unsigned char filter_datax[height][width];
	unsigned char filter_datay[height][width];
	unsigned char peak_data[height][width];
	
	//file descriptors			
	FILE *file_open,*file_write;
	
	//size of 33 and 55 matrices declaration
	const int size_33 = 3, size_55 = 5;
	
	//sobel operatot matrix for all the four filters
	int Sobel_33x[3][3] = {{-1,0,1},{-1,0,1},{-1,0,1}};
	int Sobel_33y[3][3] = {{-1,-1,-1},{0,0,0},{1,1,1}};
	int Sobel_55x[5][5] = {{ -1, -2, 0, 2, 1}, { -2, -4, 0, 4, 2}, { -4, -8, 0, 8, 4}, { -2, -4, 0, 4, 2}, { -1, -2, 0, 2, 1}};
	int Sobel_55y[5][5] = {{-1, -2, -4, -2, -1}, { -2, -4, -8, -4, -2}, { 0, 0, 0, 0, 0}, { 2, 4, 8, 4, 2}, { 1, 2, 4, 2, 1}};
	
	
	//opening the raw image file
	file_open=fopen("raw_orig.raw","rb");
	if(!file_open)
		{
		 printf("Cannot open the raw image file \n");
		}
	
	// Reading the raw image data into variable
	fread(Image_data,sizeof(unsigned char),(height *width),file_open);
	
	//closing the file pointer file_open after reading data
	fclose(file_open); 
	
	printf("\n\t Select from below");
	printf("\n\t 1. Horizontal 3X3");
	printf("\n\t 2. Vertical 3X3");
	printf("\n\t 3. Horizontal 5X5");
	printf("\n\t 4. Vertical 5X5");
	printf("\n\t 5. Gradient image for 3X3");
	printf("\n\t 6. Gradient image for 5X5");
	printf("\n\t 7. Edges with peak of gradient values over threshold 3X3");
	printf("\n\t 8. Edges with peak of gradient values over threshold 5X5");
	printf("\n\t 9. Exit");
	printf("\n\n Enter Your choice: ");
	scanf("%d", &ch);
	switch(ch) {
	case 1 :
		// Horizontal 3X3 sober Filter application
		for (j = 0; j < height; j++) {
			for ( i = 0; i < width; i++) {
				total = 0;
				for (y = 0; y < size_33; y++) {
					for ( x = 0; x < size_33; x++) {
						total += Image_data[y + j ][x + i ] * Sobel_33x[y][x];
					}
				filter_data[j][i] = (total / 4) + 128; 
				}
			}
		}
		
		//open a file to write the modified image data
		file_write=fopen("horizontal_33.raw","wb");
		//write the image into the file using the file descriptor
		fwrite(filter_data,sizeof(unsigned char),sizeof(filter_data),file_write);
		//close the file pointer after completion of writing the data into file
		fclose(file_write); 
		break;
	
	case 2 :
		// Vertical 3X3 sober Filter application
		for (j = 0; j < height ; j++) {
			for ( i = 0; i < width; i++) {
				total = 0;
				for (y = 0; y < size_33; y++) {
					for ( x = 0; x < size_33; x++) {
						total += Image_data[y + j][x + i] * Sobel_33y[y][x];
					}
				filter_data[j][i] = (total / 4) + 128; 
				}
			}
		}
		
		//open a file to write the modified image data
		file_write=fopen("verical_33.raw","wb");
		//write the image into the file using the file descriptor
		fwrite(filter_data,sizeof(unsigned char),sizeof(filter_data),file_write);
		//close the file pointer after completion of writing the data into file
		fclose(file_write);
		break;
	
	case 3:
		// Horizontal 5X5 sober Filter application
		for (j = 0; j < height ; j++) {
			for ( i = 0; i < width ; i++) {
				total = 0;
				for (y = 0; y < size_55; y++) {
					for ( x = 0; x < size_55; x++) {
						total += Image_data[y + j ][x + i ] * Sobel_55x[y][x];
					}
				filter_data[j][i] = (total / 10) + 128;
				}
			}
		}
		
		//open a file to write the modified image data
		file_write=fopen("horizontal_55.raw","wb");
		//write the image into the file using the file descriptor
		fwrite(filter_data,sizeof(unsigned char),sizeof(filter_data),file_write);
		//close the file pointer after completion of writing the data into file
		fclose(file_write);
		break;
	       
	case 4 :
		// Vertical 5X5 sober Filter application
		for (j = 0; j < height ; j++) {
			for ( i = 0; i < width ; i++) {
				total = 0;
				for (y = 0; y < size_55; y++) {
					for ( x = 0; x < size_55; x++) {
						total += Image_data[y + j ][x + i ] * Sobel_55y[y][x];
					}
				filter_data[j][i] = (total / 10) + 128; 
				}
			}
		}
	
		//open a file to write the modified image data
		file_write=fopen("vertical_55.raw","wb");
		//write the image into the file using the file descriptor
		fwrite(filter_data,sizeof(unsigned char),sizeof(filter_data),file_write);
		//close the file pointer after completion of writing the data into file
		fclose(file_write); 
		break;
	case 7:
	case 5: 
	// Horizontal 3X3 sober Filter application
		for (j = 0; j < height; j++) {
			for ( i = 0; i < width; i++) {
				total = 0;
				for (y = 0; y < size_33; y++) {
					for ( x = 0; x < size_33; x++) {
						total += Image_data[y + j ][x + i ] * Sobel_33x[y][x];
					}
				filter_datax[j][i] = total/30; 
				}
			}
		}
		
	// Vertical 3X3 sober Filter application
		for (j = 0; j < height ; j++) {
			for ( i = 0; i < width; i++) {
				total = 0;
				for (y = 0; y < size_33; y++) {
					for ( x = 0; x < size_33; x++) {
						total += Image_data[y + j][x + i] * Sobel_33y[y][x];
					}
				filter_datay[j][i] = total / 30; 
				}
			}
		}	
		
		//computing the gradient
		
		for (j = 0; j < height ; j++) {
			for ( i = 0; i < width ; i++) {	
				filter_data[j][i] = sqrt ( (filter_datax[j][i] * filter_datax[j][i]) + (filter_datay[j][i] * filter_datay[j][i]));
			}
		}	
		if(ch == 5){
		//open a file to write the modified image data
		file_write=fopen("gradient33.raw","wb");
		//write the image into the file using the file descriptor
		fwrite(filter_data,sizeof(unsigned char),sizeof(filter_data),file_write);
		//close the file pointer after completion of writing the data into file
		fclose(file_write); 
		}
		if(ch == 7){
		threshold = 120;
    // getting the peak gradient data using the threshold
		for ( i = 0; i < height; i++){
			for( j = 0; j < width; j++){	
				if(filter_data[i][j] > 0 ){
					peak_data[i][j] = 0;
	            	if(filter_data[i][j] > 0){
				   		if(filter_data[i][j] > filter_data[i-1][j] && filter_data[i][j] >= filter_data[i+1][j] && filter_data[i][j] > threshold ||
	               	  filter_data[i][j] < filter_data[i-1][j] && filter_data[i][j] <= filter_data[i+1][j] && filter_data[i][j] < -threshold )
							peak_data[i][j] = 255;
				   		else if(filter_data[i][j] > filter_data[i][j-1] && filter_data[i][j] >= filter_data[i][j+1] && filter_data[i][j] > threshold ||
	               		   filter_data[i][j] < filter_data[i][j-1] && filter_data[i][j] <= filter_data[i][j+1] && filter_data[i][j] < -threshold )
							peak_data[i][j] = 255;
	           		}
				}	

			}
		}
		//open a file to write the modified image data
		file_write=fopen("threshold33.raw","wb");
		//write the image into the file using the file descriptor
		fwrite(peak_data,sizeof(unsigned char),sizeof(peak_data),file_write);
		//close the file pointer after completion of writing the data into file
		fclose(file_write); 
	}
		break;
		
	case 8 :	
	case 6 : 
	// Horizontal 5X5 sober Filter application
		for (j = 0; j < height ; j++) {
			for ( i = 0 ; i < width ; i++) {
				total = 0;
				for (y = 0; y < size_55; y++) {
					for ( x = 0; x < size_55; x++) {
						total += Image_data[y + j ][x + i ] * Sobel_55x[y][x];
					}
				filter_datax[j][i] = total/200 ;
				}
			}
		}
		
		// Vertical 5X5 sober Filter application
		for (j = 0; j < height ; j++) {
			for ( i = 0; i < width ; i++) {
				total = 0;
				for (y = 0; y < size_55; y++) {
					for ( x = 0; x < size_55; x++) {
						total += Image_data[y + j ][x + i ] * Sobel_55y[y][x];
					}
				filter_datay[j][i] = total/200; 
				}
			}
		}
	
		//computing the gradient
		for (j = 0; j < height ; j++) {
			for ( i = 0; i < width ; i++) {	
				filter_data[j][i] = sqrt ( (filter_datax[j][i] * filter_datax[j][i]) + (filter_datay[j][i] * filter_datay[j][i]));
			}
		}	
		
		if(ch == 6){
		//open a file to write the modified image data
		file_write=fopen("gradient55.raw","wb");
		//write the image into the file using the file descriptor
		fwrite(filter_data,sizeof(unsigned char),sizeof(filter_data),file_write);
		//close the file pointer after completion of writing the data into file
		fclose(file_write); 
		}		
		if(ch == 8){
		threshold = 120;
    // getting the peak gradient data using the threshold
		for ( i = 0; i < height; i++){
			for( j = 0; j < width; j++){	
				if(filter_data[i][j] > 0 ){
					peak_data[i][j] = 0;
	            	if(filter_data[i][j] > 0){
				   		if(filter_data[i][j] > filter_data[i-1][j] && filter_data[i][j] >= filter_data[i+1][j] && filter_data[i][j] > threshold ||
	               	  filter_data[i][j] < filter_data[i-1][j] && filter_data[i][j] <= filter_data[i+1][j] && filter_data[i][j] < -threshold )
							peak_data[i][j] = 255;
				   		else if(filter_data[i][j] > filter_data[i][j-1] && filter_data[i][j] >= filter_data[i][j+1] && filter_data[i][j] > threshold ||
	               		   filter_data[i][j] < filter_data[i][j-1] && filter_data[i][j] <= filter_data[i][j+1] && filter_data[i][j] < -threshold )
							peak_data[i][j] = 255;
	           		}
				}	

			}
		}
		//open a file to write the modified image data
		file_write=fopen("threshold55.raw","wb");
		//write the image into the file using the file descriptor
		fwrite(peak_data,sizeof(unsigned char),sizeof(peak_data),file_write);
		//close the file pointer after completion of writing the data into file
		fclose(file_write); 
	}
	break;
	case 9 : exit(0); //exit the program
	break;
	
	default : printf("Invalid option\n" );
	}
			   
	return 0;
}
