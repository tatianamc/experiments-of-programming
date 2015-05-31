package com.mongodb;

import spark.Request;
import spark.Response;
import spark.Route;
import spark.Spark;

import static spark.Spark.*;

import java.util.UnknownFormatConversionException;

public class HelloWorldSparkStyle {
    public static void main(String[] args) {


//        Spark.get("/",new Route() {
//
//            @Override
//            public Object handle(Request request, Response response) throws Exception {
//                return "Hello world From Spark )";
//            }
//        });

        //java 8 style
        get("/", (req, res) -> "Hello World");
    }
}
