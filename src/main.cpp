/*
 * main.cpp
 *
 *  Created on: Aug. 24, 2022
 *      Author: MrMouse
 */

#include "discreteFT.h"
#include <time.h>
#include <iostream>

using namespace std;

int main() {
	/*
	read_data();
	discrete_ft inst();
	start_timer();
	inst.fft()
	stop_timer() and print time;
	start_timer();
	inst.dft()
	stop_timer(); and print time;
	write_data(); (to plot in matlab)
	*/

	discreteFT fft_calculator;

	clock_t start=0, finish=0;
	cout << "STARTING DFT USING N^2 ALGORITHM" << endl;
	start = clock();
	fft_calculator.dft();
	finish = clock();
	cout << (1e3 * (finish - start)/CLOCKS_PER_SEC) << " msec to complete O(N^2) DFT." << endl;

	start = 0, finish = 0;
	cout << "STARTING FFT USING Nlog(N) ALGORITHM" << endl;
	start = clock();
	fft_calculator.fft();
	finish = clock();
	cout << (1e3 * (finish - start)/CLOCKS_PER_SEC) << " msec to complete O(Nlog(N)) FFT." << endl;

	//fft_calculator.print_W();
	fft_calculator.print_output(true);
	//fft_calculator.print_output_mag();

	fft_calculator.get_magnitude(true);
	fft_calculator.write_data();

	return 0;
}


