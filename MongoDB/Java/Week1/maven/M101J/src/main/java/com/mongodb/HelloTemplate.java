package com.mongodb;


import freemarker.template.Configuration;
import freemarker.template.Template;
import freemarker.template.TemplateException;

import java.io.IOException;
import java.io.StringWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Objects;

public class HelloTemplate {

    public static void main(String[] args) {
        Configuration configuration = new Configuration();
        configuration.setClassForTemplateLoading(HelloTemplate.class,"/");

        try {
            Template template = configuration.getTemplate("hello.ftl");
            StringWriter writer = new StringWriter();
            Map<String,Object> map = new HashMap<>();
            map.put("name", "Igor");

            template.process(map,writer);
            System.out.println(writer);
        } catch (IOException e) {
            e.printStackTrace();
        } catch (TemplateException e) {
            e.printStackTrace();
        }
    }

}
