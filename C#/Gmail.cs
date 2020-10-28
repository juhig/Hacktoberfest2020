using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Mail;
using System.Text;
using System.Threading.Tasks;

namespace Email
{
    class Program
    {
        static void Main(string[] args)
        {
            /*
            ----------------------------------------------------------------------------
            ------- > You need to enable Less secure apps on your Google Account <------
            ----------------------------------------------------------------------------
             
             */
            string to = ""; // Whom to send (Email address)
            string from = ""; // Your Email (Email address)
            string header = ""; // Email header
            string subject = ""; // Email Subject
            string msg = ""; // Email Body

            string password = ""; // Your Email Password

            Console.WriteLine("Enter your email address");
            from = Convert.ToString(Console.ReadLine());
            Console.WriteLine("Enter your password");
            password = Convert.ToString(Console.ReadLine());
            Console.WriteLine("Enter the mail header");
            header = Convert.ToString(Console.ReadLine());
            
            Console.WriteLine("Enter the reciever's email");
            to = Convert.ToString(Console.ReadLine());

            Console.WriteLine("Subject of email");
            subject = Convert.ToString(Console.ReadLine());

            Console.WriteLine("Type the message");
            msg = Convert.ToString(Console.ReadLine());

            System.Net.Mail.MailMessage eemail = new System.Net.Mail.MailMessage();
            eemail.To.Add(to);
            eemail.From = new MailAddress(from, header, System.Text.Encoding.UTF8);
            eemail.Subject = subject;
            eemail.SubjectEncoding = System.Text.Encoding.UTF8;
            eemail.Body = msg;
            eemail.BodyEncoding = System.Text.Encoding.UTF8;
            eemail.IsBodyHtml = true;
            eemail.Priority = MailPriority.High;
            SmtpClient client = new SmtpClient();
            client.Credentials = new System.Net.NetworkCredential(from, password);
            client.Port = 587;
            client.Host = "smtp.gmail.com";
            client.EnableSsl = true;
            try
            {
                client.Send(eemail);
                Console.WriteLine("Email Send");

            }
            catch (Exception ex)
            {
                Exception ex2 = ex;
                string errorMessage = string.Empty;
                while (ex2 != null)
                {
                    errorMessage += ex2.ToString();
                    ex2 = ex2.InnerException;
                }

            }

            Console.ReadKey();
        }
    }
}
