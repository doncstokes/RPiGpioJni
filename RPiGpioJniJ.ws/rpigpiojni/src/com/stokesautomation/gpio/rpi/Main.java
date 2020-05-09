package com.stokesautomation.gpio.rpi;

/**
 * This is a test program for the JNI wrapper RPiGpio.
 * <p>
 * <b>Caution:</b> This test configures a GPIO output that could damage
 * the Raspberry Pi or connected hardware if improperly connected!
 * </p>
 * @author don
 */
public class Main {
	
	static int gpioBlink = 17; // BCM 17 is physical pin 11.
	static int gpioPoll  = 27; // BCM 27 is physical pin 13.
	
	RPiGpio rpiGpio = null;
	int status = 0;
	
	private Main() throws Exception {
		rpiGpio = new RPiGpio();
		int libVer = rpiGpio.getVersion();
		System.out.println("Version " + libVer);
		int result = rpiGpio.setup();
		status = result;
	}
	
	private void cleanup() {
		rpiGpio.cleanup();
	}
	
	private void blink() throws Exception {
		System.out.println("Blinking ...");
		rpiGpio.setup_gpio(gpioBlink, RPiGpio.OUTPUT, RPiGpio.PUD_OFF);
		boolean val = false;
		
		for (int i = 0; i < 8; i++) {
			val = !val;
			rpiGpio.output_gpio(gpioBlink, val ? 1 : 0);
			Thread.sleep(3 * 1000);
		}
		System.out.println("Done Blinking");
	}
	
	private void poll() throws Exception {
		System.out.println("Polling ...");
		rpiGpio.setup_gpio(gpioPoll, RPiGpio.INPUT, RPiGpio.PUD_UP);		
		long timeNow = System.currentTimeMillis();
		long timeEnd = timeNow + 1000 * 60;
		int val = -1;
		while (timeNow < timeEnd) {
			int newVal = rpiGpio.input_gpio(gpioPoll);
			if (val != newVal) {
				System.out.println("Input = " + newVal);
				val = newVal;
			}
			Thread.sleep(100);
			timeNow = System.currentTimeMillis();
		}
		System.out.println("Done Polling");
	}
	

	public static void main(String[] args) {
		try {
			Main app = new Main();
			System.out.println("status = " + app.status);
			app.blink();
			app.poll();
			app.cleanup();
		} catch (Throwable t) {
			System.err.println("CAUGHT: " + t.toString());
			t.printStackTrace(System.err);
		}
	}
}
