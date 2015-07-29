package com.nesterenya;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.net.MalformedURLException;
import java.net.URL;

/**
 * Created by igor on 29.07.2015.
 */
public class ImgSave {
    public static void main(String[] args) throws IOException {
        URL url = new URL("http://www.avajava.com/images/avajavalogo.jpg");
        BufferedImage image = ImageIO.read(url);
        ImageIO.write(image,"png", new File("src/main/java/com/nesterenya/file.png"));
    }
}
