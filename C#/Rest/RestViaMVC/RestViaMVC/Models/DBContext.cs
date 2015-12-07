using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;

using System.Web;
//Enable-Migrations
//Add-Migration AddDb
// Update-Database

namespace RestViaMVC.Models
{
    public class Context : DbContext
    {
        public Context() : base("MyDatabase")
        {

        }

        public virtual DbSet<Ticket> Tickets { get; set; }
    }
}