package com.nesterenya;

import org.jsoup.Connection;
import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

import javax.imageio.ImageIO;
import java.io.IOException;
import java.text.NumberFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

/**
 * Created by igor on 29.07.2015.
 */
public class Gohome {
    final static String BASE_URL = "http://gohome.by";

    public static void main(String[] args) throws IOException, ParseException {

        //Connection connection = Jsoup.connect("http://gohome.by/rent/search").data("search[type]", "3").data("search[region]", "4");
        //search[region]  4
        //Document document = connection.post();

        Document document = Jsoup.connect("http://gohome.by/rent/flat/gomel").get();

        Element items = document.getElementById("list_items");
        Elements rows = items.getElementsByClass("head");

        List<String> links = new ArrayList<>();

        for (Element e : rows) {
            Element firstLink = e.getElementsByTag("a").first();
            links.add(firstLink.attr("href"));
        }

        List<Ad> ads = new ArrayList<>();
        for(String link: links) {
            Ad ad = parseAd(Jsoup.connect(BASE_URL+link).get());
            System.out.println(ad);
        }

    }

    private static Ad parseAd(Document adDoc) throws ParseException {

        //Element content = adDoc.getElementById("content");
        Element adElement = adDoc.getElementById("new_ad");

        Element h1 = adElement.getElementsByTag("h1").first();
        Element views = adElement.getElementsByClass("views").first();
        Elements bb = views.getElementsByTag("b");
        Ad ad = new Ad();
        ad.setDate(parseDate(bb));
        ad.setViews(parseViews(bb));

        // images
        Element imagesBlock = adElement.getElementsByClass("block_images").first();
        if(imagesBlock!=null) {
            List<String> images = parseImageLinks(imagesBlock);
        }
        // TODO save images

        Elements blocks = adElement.getElementsByClass("block");

        String address = parseAddress(blocks.get(0));
        ad.setAddress(address);

        ad.setRoomCount(parseRooms(blocks.get(0)));
        ad.setCost(parseCost(blocks.get(0)));

        ad.setSource(BASE_URL);

        ad.setContacts(parseContacts(blocks.get(3)));
        ad.setDescription(parseDescription(blocks.get(2)));

        return ad;
    }

    private static String parseContacts(Element block) {
        Elements trs = block.getElementsByTag("tr");
        String email = trs.get(0).getElementsByTag("td").get(1).html();

        String[] parts = email.split("<a class=\"dog\"></a>");
        email = parts[0] + "@"+ parts[1];

        String phone = trs.get(2).getElementsByTag("td").get(1).text();

        return phone+", " + email;
    }

    private static String parseDescription(Element block) {
        Elements trs = block.getElementsByTag("tr");
        String description = trs.get(0).getElementsByTag("td").get(1).text();
        return  description;
    }

    private static String parseAddress(Element block) {
        Elements trs = block.getElementsByTag("tr");

        String town = trs.get(0).getElementsByTag("td").get(1).getElementsByTag("a").first().text();
        String street = trs.get(1).getElementsByTag("td").get(1).text();
        return town+", "+street;
    }

    private static int parseRooms(Element block) throws ParseException {
        Elements trs = block.getElementsByTag("tr");
        String rooms = trs.get(2).getElementsByTag("td").get(1).text();
        return Integer.parseInt(rooms.split("-")[0]);
    }

    private static String parseCost(Element block) {
        Elements trs = block.getElementsByTag("tr");
        String cost = trs.get(3).getElementsByTag("td").get(1).text();
        return cost;
    }

    private static List<String> parseImageLinks(Element imagesBlock) {
        List<String> imgs = new ArrayList<>();
        Elements imgElements = imagesBlock.getElementsByTag("a");
        if(imgElements!=null) {
            for (Element e : imgElements) {
                imgs.add(e.attr("href"));
            }
        }
        return imgs;
    }

    private static int parseViews(Elements bb) {

        int views = 0;
        try {
            if(bb.size()==3) {
                views = Integer.parseInt(bb.get(2).text());
            } else {
                views = Integer.parseInt(bb.get(1).text());
            }
        } catch (Exception ex) {
            views = 0;
        }

        return views;
    }

    private static Date parseDate(Elements bb) throws ParseException {
        SimpleDateFormat sdf = new SimpleDateFormat("dd-MM-yyyy");
        return (bb.size()==3)?sdf.parse(bb.get(1).text()):sdf.parse(bb.get(0).text());
    }

}
