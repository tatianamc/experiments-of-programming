package by.nesterione.experiments.swing;

import java.awt.Canvas;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.beans.BeanInfo;
import java.beans.Beans;
import java.beans.EventSetDescriptor;
import java.beans.Introspector;
import java.beans.PropertyDescriptor;
import java.beans.SimpleBeanInfo;
import java.io.Serializable;
import java.awt.*;

//Самодиогностика кампонента
public class DemoBeans {
	public static void main(String[] args) {
		try {
			Class<?> c = Colors.class;//Class.forName("Colors");
			BeanInfo BeansInfo = Introspector.getBeanInfo(c);
			
			System.out.println("Свойства:");
			PropertyDescriptor propertyDescriptor[] = 
					BeansInfo.getPropertyDescriptors();
			for(int i = 0; i< propertyDescriptor.length; i++) {
				System.out.println(propertyDescriptor[i].getName());
			}
			
			System.out.println("События:");
			EventSetDescriptor eventSetDescriptor[] = BeansInfo.getEventSetDescriptors();
			for(int i =0; i< eventSetDescriptor.length;i++) {
				System.out.println(eventSetDescriptor[i].getName());
			}
			
		} catch(Exception ex) {
			System.out.println(ex);
		}
	}
}

class Colors extends Canvas implements Serializable {
	transient private Color color;
	private boolean rectangular;
	
	public Colors() {
		addMouseListener(new MouseAdapter() {
			public void mousePressed(MouseEvent me) {
				change();
			}
		});
		rectangular = false;
		setSize(200,100);
		change();
	}
	
	public boolean getRectangular() {
		return rectangular;
	}
	
	public void setRectangular(boolean flag) {
		this.rectangular = flag;
		repaint();
	}
	
	public void change() {
		color = randomColor();
		repaint();
	}
	
	private Color randomColor() {
		int r = (int) (255*Math.random());
		int g = (int) (255*Math.random());
		int b = (int) (255*Math.random());
		return new Color(r,g,b);
	}
	
	public void paint(Graphics g) {
		Dimension d = getSize();
		int h = d.height;
		int w = d.width;
		g.setColor(color);
		if(rectangular) {
			g.fillRect(0, 0, w-1, h-1);
		}
		else {
			g.fillOval(0, 0, w-1, h-1);
		}
	}
}

class ColorsBeansInfo extends SimpleBeanInfo {
	public PropertyDescriptor[] getPropertyDescriptors() {
		try {
			PropertyDescriptor rectangular = new 
					PropertyDescriptor("rectangular", Colors.class);
			PropertyDescriptor pd[] = {rectangular};
			return pd;
		} catch ( Exception e) {
			System.out.println("Ex");
		}
		return null;
	}
}