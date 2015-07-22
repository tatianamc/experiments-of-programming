package com.nesterenya;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/**
 * Hello world!
 *
 */
public class App 
{
    public static void main( String[] args ) throws IOException {
        String url = "http://www.hatu.by/";
        Document document = Jsoup.connect(url).get();
        Element element = document.getElementById("list");
        Elements elements = element.getElementsByClass("box-container");

        List<String> headers = new ArrayList<String>();
        for(Element e: elements) {

            Element a = e.getElementsByTag("h2").first().getElementsByTag("a").first();
            headers.add(  a.text() );

        }



        headers.stream().forEach(System.out::println);

    }
}
