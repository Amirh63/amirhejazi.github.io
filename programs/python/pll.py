#!/usr/bin/python

import numpy as np
import pdb
import matplotlib.pyplot as plt
import sys
import os
import math

def main():
	os.system('clear')

	samples 	= 200
	phi 		= 0.0
	freq_offset     = 0.08
	int_1 		= 0
	int_2 		= 0
	phaseAcumm      = 0
	bw 	    	= 180
	theta_0 	= (2*math.pi)/bw				
	eta 		= np.sqrt(2)/2
	k_i 		= (4*theta_0*theta_0)/(1+2*eta*theta_0+theta_0*theta_0)          # proportional gain
	k_p 		= (4*eta*theta_0)/(1+2*eta*theta_0+theta_0*theta_0)              # integral gain

	input_sig_sav_real = []
	input_sig_sav_imag = []
	phase_diff         = []
	output_loop_filter = []
	output_signal_real = []
	output_signal_imag = []
	for x in range(0, samples - 1):
        #DDS
		phi 	  = phi + freq_offset 
		input_sig = np.exp(1j * phi * math.pi * 2)
		input_sig_sav_real.append(input_sig.real)
		input_sig_sav_imag.append(input_sig.imag)
		
		#phase detector
		vco 	  = np.exp(1j * int_2 * math.pi * 2)
		product   = input_sig * np.conj(vco)
		detector  = np.angle(product)/(2 * math.pi)
		phase_diff.append(detector)

		#loop filter 
		int_1 	  = int_1 + k_i * detector
		delta_phi = int_1 + k_p * detector
		output_loop_filter.append(delta_phi)

		#phase accumulator 
		output_signal_real.append(phaseAcumm.real)
		output_signal_imag.append(phaseAcumm.imag)
		int_2 	  = int_2 + delta_phi
		phaseAcumm= np.exp(1j * 2 * math.pi * int_2)

	plt.figure(1)
	plt.subplot(211)
	plt.plot(input_sig_sav_real, 'b')
	plt.plot(output_signal_real, 'r')
	plt.grid()
	plt.title("Real part of output signal(red) V.S. real part of input signal(blue)")
	plt.ylabel("Amplitude")
	plt.xlabel("Samples")

	plt.subplot(212)
	plt.plot(input_sig_sav_imag, 'b')
	plt.plot(output_signal_imag, 'r')
	plt.grid()
	plt.title("Imaginary part of output signal(red) v.s. imaginary part of input signal(blue)")
	plt.ylabel("Amplitude")
	plt.xlabel("Samples")

	plt.figure(2)
	plt.plot(phase_diff)
	plt.grid()
	plt.title("Phase difference b/w the two signals")
	plt.ylabel("Radian")
	plt.xlabel("Samples")
	
	plt.show()

if __name__ == '__main__':
	sys.exit(main())
