package com.nesterenya;

import java.util.Date;


public class Ad {

	private String id;
	private String address;
	private String cost;
	private Date date;
	private int roomCount;
	private String description;
	private String contacts;

	public int getViews() {
		return views;
	}

	public void setViews(int views) {
		this.views = views;
	}

	private int views;

	public String getSource() {
		return source;
	}

	public void setSource(String source) {
		this.source = source;
	}

	private String source;
	
	public Ad() {
		this.id = "f";
	}	
	
	public Ad(String address, String cost, Date date, int roomCount,
			String description, String contacts) {
		super();
		this.id = "f";
		this.address = address;
		this.cost = cost;
		this.date = date;
		this.roomCount = roomCount;
		this.description = description;
		this.contacts = contacts;
	}
	
	public String getId() {
		return id;
	}

	public void setId(String id) {
		this.id = id;
	}
	
	public String getAddress() {
		return address;
	}
	public void setAddress(String address) {
		this.address = address;
	}
	public String getCost() {
		return cost;
	}
	public void setCost(String cost) {
		this.cost = cost;
	}
	public Date getDate() {
		return date;
	}
	public void setDate(Date date) {
		this.date = date;
	}
	public int getRoomCount() {
		return roomCount;
	}
	public void setRoomCount(int roomCount) {
		this.roomCount = roomCount;
	}
	public String getDescription() {
		return description;
	}
	public void setDescription(String description) {
		this.description = description;
	}
	public String getContacts() {
		return contacts;
	}
	public void setContacts(String contacts) {
		this.contacts = contacts;
	}

	@Override
	public String toString() {
		return "Ad{" +
				"id='" + id + '\'' +
				", address='" + address + '\'' +
				", cost='" + cost + '\'' +
				", date=" + date +
				", roomCount=" + roomCount +
				", description='" + description + '\'' +
				", contacts='" + contacts + '\'' +
				", views=" + views +
				", source='" + source + '\'' +
				'}';
	}
}
