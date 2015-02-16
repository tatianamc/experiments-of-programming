
package by.nesterione.experiments;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class TestRegex {
	public static void main(String[] args) {
		Pattern p = Pattern.compile("ds+f");
		Matcher m = p.matcher("dsssf");
		System.out.println(m.matches()); 
	}
}
