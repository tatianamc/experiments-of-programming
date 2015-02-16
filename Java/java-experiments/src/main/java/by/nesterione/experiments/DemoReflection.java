package by.nesterione.experiments;

import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.Method;

public class DemoReflection {
	public static void main(String[] args) {
		try {
			Class<?> c = Class.forName("java.awt.Dimension");
			System.out.println("Constructors");
			Constructor constructor[] = c.getConstructors();
			for(int i = 0; i < constructor.length;i++) {
				System.out.println(constructor[i]);
			}
			System.out.println("Fields");
			Field fields[] = c.getFields();
			for(int i = 0; i < fields.length;i++) {
				System.out.println(fields[i]);
			}
			System.out.println("Methods");
			Method methods[] = c.getMethods();
			for(int i = 0; i < methods.length;i++) {
				System.out.println(methods[i]);
			}
		} catch (Exception e) {
			System.out.println(e);
		}
	}
}
