/*
 * discreteFT.h
 *
 *  Created on: Aug. 24, 2022
 *      Author: MrMouse
 */

#ifndef DISCRETEFT_H_
#define DISCRETEFT_H_

#define N 64

class discreteFT{
public:
	discreteFT();
	void fft_setup();
	void fft();
	void dft();
	void get_magnitude(bool);
	void read_data();
	void write_data();

//DEBUG
	void print_input();
	void print_W();
	void print_output(bool);
	void print_output_mag();

private:
	void fft_recursive(float data[][2], int SIZE);
	float input_data [N];
	float W [N][2]; //complex data requires two fields
	float output_data_fast [N][2]; //complex data requires two fields
	float output_data [N][2]; //complex data requires two fields
	float output_data_mag [N]; //magnitude plot
};

#endif /* DISCRETEFT_H_ */
