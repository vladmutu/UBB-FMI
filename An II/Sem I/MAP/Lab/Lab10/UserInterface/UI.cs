using Lab10.Services;
using Lab10.Domain;

namespace Lab10.UserInterface
{
    internal class UI
    {
        private Service service;
        private Dictionary<int, Action> commands;

        public UI(Service service)
        {
            this.service = service;

            // Initialize commands using delegates
            commands = new Dictionary<int, Action>
            {
                { 0, () => Environment.Exit(0) },
                { 1, AfiseazaJucatoriiEchipei },
                { 2, AfiseazaJucatoriiActiviDinMeci },
                { 3, AfiseazaMeciurileDinPerioada },
                { 4, AfiseazaScorulMeciului }
            };
        }

        private int ReadId()
        {
            Console.WriteLine("Introduceti ID-ul:");
            return int.Parse(Console.ReadLine());
        }

        private DateTime ReadDate()
        {
            Console.WriteLine("Introduceti data (format MM/dd/yyyy):");
            return DateTime.Parse(Console.ReadLine());
        }

        private void AfiseazaJucatoriiEchipei()
        {
            int teamId = ReadId();
            Echipa team = service.findEchipa(teamId);
            Console.WriteLine($"Jucatorii echipei {team.Name} sunt:");
            foreach (var player in service.JucatoriiEchipeiX(team))
            {
                Console.WriteLine($"{player.Name}, {player.School}");
            }
        }

        private void AfiseazaJucatoriiActiviDinMeci()
        {
            int teamId = ReadId();
            int matchId = ReadId();
            Echipa team = service.findEchipa(teamId);
            Meci match = service.findMeci(matchId);
            Console.WriteLine($"Jucatorii activi ai echipei {team.Name} din meciul din {match.Date} sunt:");
            foreach (var player in service.JucatoriiActiviAiUneiEchipeDeLaMeciulX(team, match))
            {
                Console.WriteLine($"{player.Name}, {player.School}");
            }
        }

        private void AfiseazaMeciurileDinPerioada()
        {
            DateTime startDate = ReadDate();
            DateTime endDate = ReadDate();
            foreach (var match in service.MeciuriDinPerioadaX(startDate, endDate))
            {
                Console.WriteLine($"{match.Echipa1.Name} vs {match.Echipa2.Name} din {match.Date}");
            }
        }

        private void AfiseazaScorulMeciului()
        {
            int matchId = ReadId();
            Meci match = service.findMeci(matchId);
            Console.WriteLine($"Scorul meciului dintre {match.Echipa1.Name} si {match.Echipa2.Name} din {match.Date} este: {service.ScorulUnuiMeci(match)}");
        }

        public void run()
        {
            while (true)
            {
                Console.WriteLine("\n--------------------------------------------------");
                Console.WriteLine("0 - Iesire");
                Console.WriteLine("1 - Afiseaza toti jucatorii unei echipe");
                Console.WriteLine("2 - Afiseaza toti jucatorii activi ai unei echipe intr-un meci");
                Console.WriteLine("3 - Afiseaza toate meciurile dintr-o anumita perioada");
                Console.WriteLine("4 - Afiseaza scorul unui meci");
                Console.WriteLine("--------------------------------------------------\n");

                Console.Write(">>> ");
                try
                {
                    int cmd = int.Parse(Console.ReadLine());
                    if (commands.TryGetValue(cmd, out var action))
                    {
                        action();
                    }
                    else
                    {
                        Console.WriteLine("Comanda invalida"); 
                    }
                }
                catch (Exception e)
                {
                    Console.WriteLine(e.Message);
                }
                
            }
        }
    }
}
