package com.nesterenya;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

import java.io.IOException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

/**
 * Hello world!
 */
public class App {
    public static void main(String[] args) throws IOException {

        try {
            for (int i = 0; i < 2; i++) {


            String url = "http://www.hatu.by/ad/search/minsk/"+i+"/list.do";
            Document document = Jsoup.connect(url).get();
            Element element = document.getElementById("list");
            Elements elements = element.getElementsByClass("box-container");

            List<Ad> ads = new ArrayList<>();

            SimpleDateFormat simpleDateFormat = new SimpleDateFormat("dd.MM.yyyy");

            for (Element e : elements) {

                Ad ad = new Ad();
                Element a = e.getElementsByTag("h2").first().getElementsByTag("a").first();
                ad.setAddress(a.text());

                String price = e.getElementsByClass("price").first().text();
                ad.setCost(price);

                Element note = e.getElementsByClass("note").first();
                Elements strongs = note.getElementsByTag("strong");

                String stringDate = strongs.get(0).text();
                Date date = simpleDateFormat.parse(stringDate);
                ad.setDate(date);

                String stringCnt = strongs.get(1).text();
                int roomCnt = Integer.parseInt(stringCnt);
                ad.setRoomCount(roomCnt);

                String discr = e.getElementsByAttributeValue("itemprop","description").text();
                ad.setDescription(discr);

                String contact = e.getElementsByClass("psevdo").get(1).text();
                ad.setContacts(contact);
                ads.add(ad);

                ad.setSource("http://www.hatu.by/");
            }

            ads.stream().forEach(System.out::println);
            }
        } catch (IOException ex) {
            ex.printStackTrace();
        } catch (ParseException e) {
            e.printStackTrace();
        }

    }
}
