package server;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;

public class WordExistsChecker {

    public static void main(String[] args) throws IOException {
        System.out.println(WordExistsChecker.check("wordf"));
    }

    private static String URL_TO_CHECK = "https://en.wiktionary.org/w/api.php?action=query&format=json&titles=";

    private WordExistsChecker() {

    }

    public static boolean check(String word) throws IOException {
        boolean isExists = false;

        URL url;
        HttpURLConnection conn;


        url = new URL(URL_TO_CHECK + word);
        conn = (HttpURLConnection) url.openConnection();
        conn.setRequestMethod("GET");

        try (BufferedReader rd = new BufferedReader(new InputStreamReader(conn.getInputStream()))) {
            String line;
            StringBuilder result = new StringBuilder();
            while ((line = rd.readLine()) != null) {
                result.append(line);
            }

            isExists = !result.toString().contains("\"missing\"");
        }


        return isExists;
    }

}
