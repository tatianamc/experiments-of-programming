using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace RestViaMVC.Models
{
    public class Ticket
    {
        public int Id { get; set; }
        public String Number { get; set; }
        public String Name { get; set; }

        public Ticket() { }

        public Ticket(int id, String number, String name)
        {
            Id = id;
            Number = number;
            Name = name;
        }
    }
}