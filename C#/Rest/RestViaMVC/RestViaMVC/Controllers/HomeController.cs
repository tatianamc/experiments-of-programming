using RestViaMVC.Models;
using System.Collections.Generic;
using System.Linq;
using System.Web.Mvc;

namespace RestViaMVC.Controllers
{
    public class HomeController : Controller
    {
        [HttpGet]
        public ActionResult Index()
        {
            return View();
        }

        [HttpGet]
        public JsonResult All()
        {
            List<Ticket> tickets = new List<Ticket>();
            using (var ctx = new Context())
            {
                tickets = ctx.Tickets.ToList<Ticket>();
            }
            return Json(tickets, JsonRequestBehavior.AllowGet);
        }

        [HttpPost]
        public void Create(Ticket ticket)
        {
            using (var ctx = new Context())
            {
                ctx.Tickets.Add(ticket);
                ctx.SaveChanges();
            }
        }

        [HttpPut]
        public void Update(Ticket ticket)
        {
            using (var ctx = new Context())
            {
                var entity = ctx.Tickets.Where(x => x.Id == ticket.Id).FirstOrDefault();
                if(entity==null)
                {
                    ctx.Tickets.Add(ticket);
                } else
                {
                    entity.Name = ticket.Name;
                    entity.Number = ticket.Number;
                }
                ctx.SaveChanges();
            }
        }

        [HttpDelete]
        public void Delete(int id)
        {
            using (var ctx = new Context())
            {
                var entity = ctx.Tickets.Where(x => x.Id == id).FirstOrDefault();
                if (entity != null)
                {
                    ctx.Tickets.Remove(entity);
                    ctx.SaveChanges();
                }
            }
        }

        [HttpGet]
        public JsonResult Get(int id)
        {
            Ticket ticket = null;
            using (var ctx = new Context())
            {
                ticket = ctx.Tickets.Where(x => x.Id == id).FirstOrDefault();
            }

            return Json(ticket, JsonRequestBehavior.AllowGet);
        }
    }
}