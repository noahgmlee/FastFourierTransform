/*
 * discreteFT.cpp
 *
 *  Created on: Aug. 24, 2022
 *      Author: MrMouse
 */

#include "discreteFT.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <math.h>

using namespace std;

discreteFT :: discreteFT(){
	this->read_data();
	for (int i = 0; i < N; i++){
		this->output_data_fast[i][0] = this->input_data[i];
		this->output_data_fast[i][1] = 0.0;
	}
}

void discreteFT :: fft(){
	this->fft_recursive(this->output_data_fast, N);
	for (int k = 0; k < N; k++){
		if (abs(this->output_data_fast[k][0]) < 1e-3) {
			this->output_data_fast[k][0] = 0.0;
		}
		if (abs(this->output_data_fast[k][1]) < 1e-3) {
			this->output_data_fast[k][1] = 0.0;
		}
	}
}

void discreteFT :: fft_recursive(float data[][2], int SIZE){
	//Check if N == 2 if so compute the basic size 2 DFT butterfly and return

	//Create the even and odd data out of the input array

	//populate the even and odd data from the input array

	//Recursively treat the even and odd indexed input arrays as SIZE/2 DFT's

	//Once the even and odd DFT's are calculated and returned perform the FFT math
	//X(k) = Even(k) + W(N/SIZE*k%N) * Odd(k)
	//Add a threshold filter for close to zero values (same as with the N^2 DFT)

}

void discreteFT :: dft(){
	for (int k = 0; k < N; k++){
		float temp_result[2] = {0, 0};
		for (int n = 0; n < N; n++){
			int W_index = k*n % N;
			temp_result[0] += this->input_data[n] * W[W_index][0];
			temp_result[1] += this->input_data[n] * W[W_index][1];
		}
		this->output_data[k][0] = temp_result[0];
		this->output_data[k][1] = temp_result[1];
		if (abs(this->output_data[k][0]) < 1e-3) {
			this->output_data[k][0] = 0.0;
		}
		if (abs(this->output_data[k][1]) < 1e-3) {
			this->output_data[k][1] = 0.0;
		}
	}
}

void discreteFT :: get_magnitude(bool fast){
	if (fast){
		for (int i = 0; i < N; i++){
			this->output_data_mag[i] = (sqrt(pow(this->output_data_fast[i][0],2) +
										 	 pow(this->output_data_fast[i][1],2)))/N;
		}
	}
	else {
		for (int i = 0; i < N; i++){
			this->output_data_mag[i] = (sqrt(pow(this->output_data[i][0],2) +
										 	 pow(this->output_data[i][1],2)))/N;
		}
	}
}

void discreteFT :: read_data(){
	//Read the data vector
	string filename = "input_data.txt";
	ifstream inFile;
	inFile.open(filename.c_str());
    if (inFile.is_open())
    {
        for (int i = 0; i < N; i++)
        {
            inFile >> this->input_data[i];
            if (abs(this->input_data[i]) < 1e-5) {
            	this->input_data[i] = 0.0;
            }
        }
        inFile.close(); // CLose input file
    }
    else { //Error message
        cout << "error opening input_data.txt";
    }

    //Read the discrete complex function vector (e^(i2pi*n/N))
	string filename2 = "input_comp.txt";
	ifstream inFile2;
	inFile2.open(filename2.c_str());
	string line;
	int i = 0;
    while(std::getline(inFile2, line))
    {
    	stringstream lineStream(line);
        for (int j = 0; j < 2; j++){
        	lineStream >> W[i][j];
            	if (abs(this->W[i][j]) < 1e-5) {
            		this->W[i][j] = 0.0;
            	}
       	}
        i++;
        if (i == N){
        	break;
        }
    }
        inFile2.close(); // CLose input file
}

void discreteFT :: write_data(){
	ofstream myfile;
	  myfile.open ("fft_output.txt");
	  for (int i = 0; i < N; i++){
		  myfile << this->output_data_mag[i] << endl;
	  }
	  myfile.close();
}

void discreteFT :: print_input(){
	for (int i = 0; i < N; i++) {
		cout << input_data[i];
		cout << "\n";
	}
}

void discreteFT :: print_W(){
	for (int i = 0; i < N; i++) {
		cout << W[i][0];
		cout << " + ";
		cout << W[i][1];
		cout << "j\n";
	}
}

void discreteFT :: print_output(bool fast){
	if (fast){
		for (int i = 0; i < N; i++) {
			cout << this->output_data_fast[i][0];
			cout << " + ";
			cout << this->output_data_fast[i][1];
			cout << "j\n";
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			cout << this->output_data[i][0];
			cout << " + ";
			cout << this->output_data[i][1];
			cout << "j\n";
		}
	}
}

void discreteFT :: print_output_mag(){
	for (int i = 0; i < N; i++) {
		cout << this->output_data_mag[i];
		cout << "\n";
	}
}

