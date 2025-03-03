using System;
using Lab10.Domain;
using Lab10.Repository.FileRepo;
using Lab10.Services;
using Lab10.UserInterface;
using System.IO;
namespace Lab10
{
    internal class Program
    {
        static void Main(string[] args)
        {
            ElevFile elevFile = new ElevFile("D:\\UBB-FMI\\An II\\Sem I\\MAP\\Lab\\Lab10\\elevi.txt");
            EchipaFile echipaFile = new EchipaFile("D:\\UBB-FMI\\An II\\Sem I\\MAP\\Lab\\Lab10\\echipe.txt");
            JucatorFile jucatorFile = new JucatorFile(echipaFile, "D:\\UBB-FMI\\An II\\Sem I\\MAP\\Lab\\Lab10\\jucatori.txt");
            MeciFile meciFile = new MeciFile(echipaFile, "D:\\UBB-FMI\\An II\\Sem I\\MAP\\Lab\\Lab10\\meciuri.txt");
            JucatorActivFile jucatorActivFile = new JucatorActivFile("D:\\UBB-FMI\\An II\\Sem I\\MAP\\Lab\\Lab10\\jucatoriActivi.txt");
            Service service = new Service(echipaFile, elevFile, jucatorFile, meciFile, jucatorActivFile);
            UI console = new UI(service);
            console.run();
        }
    }
}

