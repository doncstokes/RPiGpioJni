package com.stokesautomation.gpio.rpi;

public class RPiVersionException extends RPiException {
	
	private static final long serialVersionUID = 1L;

	public RPiVersionException(int clsVer, int libVer, String libName) {
		super(String.format(
			"library lib%s.so version %d doesn't match class version %d",
			libName, libVer, clsVer));
	}
}
