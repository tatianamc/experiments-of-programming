package com.nesterenya.primes;

import org.jsoup.Connection;
import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

/**
 * Created by igor on 11.10.2015.
 */
public class ParsePrimes {

    public static void main(String[] args) throws IOException {

        //Document document = Jsoup.connect("http://compoasso.free.fr/primelistweb/page/prime/liste_online_en.php").get();
        //Element table = document.getElementsByTag("tbody").first();
//
//        primePageInput:200
//        numberInput:4391
//        nextButton:next page
//        firstPrimeHidden:4391
//        lastPrimeHidden:6113
        try(BufferedWriter writer = new BufferedWriter(new FileWriter("D:/prim1.txt"))) {
            int cnt = 6000000 / 600;
            long active = 1336450439;

            for (int i = 0; i < cnt; ) {
                Connection connection = Jsoup.connect("http://compoasso.free.fr/primelistweb/page/prime/liste_online_en.php")
                        .data("primePageInput", "600")
                        .data("nextButton", "next page")
                        .data("lastPrimeHidden", Long.toString(active + 1));

                try {
                    Document document = connection.post();
                    String s = document.getElementsByTag("table").get(0).getElementsByTag("table").get(2).text().trim();
                    String[] ss = s.split(" ");

                    active = Long.parseLong(ss[ss.length - 1]);
                    writer.write(s);
                    writer.write("\n");
                    i++;
                    System.out.println("read : "+i);
                } catch (IOException e) {
                    System.out.println("ex "+ e.getMessage());
                }
            }
        }
    }
}
