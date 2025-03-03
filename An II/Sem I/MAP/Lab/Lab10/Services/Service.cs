using System;
using System.Collections.Generic;
using System.Linq;
using Lab10.Domain;
using Lab10.Repository;

namespace Lab10.Services
{
    
    internal class Service
    {
        private IRepository<int, Echipa> echipe;
        private IRepository<int, Elev> elevi;
        private IRepository<int, Jucator> jucatori;
        private IRepository<int, Meci> meciuri;
        private IRepository<int, JucatorActiv> jucatoriActivi;

        public Service(IRepository<int, Echipa> echipe, IRepository<int, Elev> elevi, IRepository<int, Jucator> jucatori, IRepository<int, Meci> meciuri, IRepository<int, JucatorActiv> jucatoriActivi)
        {
            this.echipe = echipe;
            this.elevi = elevi;
            this.jucatori = jucatori;
            this.meciuri = meciuri;
            this.jucatoriActivi = jucatoriActivi;
        }

        public IEnumerable<Jucator> JucatoriiEchipeiX(Echipa echipa)
        {
            return jucatori.FindAll().Where(j =>
            {
                Jucator jucator = (Jucator)j;
                return j.Echipa.Equals(echipa);
            });
        }

        public IEnumerable<Jucator> JucatoriiActiviAiUneiEchipeDeLaMeciulX(Echipa echipa, Meci meci)
        {
            return
                from jucatorActiv in jucatoriActivi.FindAll()
                join jucator in jucatori.FindAll()
                on jucatorActiv.IdJucator equals jucator.Id
                where jucatorActiv.IdMeci == meci.Id && jucator.Echipa.Id == echipa.Id
                select jucator;
        }

        public IEnumerable<Meci> MeciuriDinPerioadaX(DateTime beginingDate, DateTime endingDate)
        {
            return
                from meci in meciuri.FindAll()
                where meci.Date >= beginingDate && meci.Date <= endingDate
                select meci;
        }

        public string ScorulUnuiMeci(Meci meci)
        {
            int scorEchipa1 = 0;
            try
            {
                scorEchipa1 =
                (from jucatorActiv in jucatoriActivi.FindAll()
                 join jucator in jucatori.FindAll()
                 on jucatorActiv.IdJucator equals jucator.Id
                 join echipa in echipe.FindAll()
                 on jucator.Echipa.Id equals echipa.Id
                 where jucatorActiv.IdMeci == meci.Id
                        && meci.Echipa1.Id == echipa.Id
                 select jucatorActiv.NrPuncteInscrise).Sum();
            }catch{}

            int scorEchipa2 = 0;
            try
            {
                scorEchipa2 =
                (from jucatorActiv in jucatoriActivi.FindAll()
                 join jucator in jucatori.FindAll()
                 on jucatorActiv.IdJucator equals jucator.Id
                 join echipa in echipe.FindAll()
                 on jucator.Echipa.Id equals echipa.Id
                 where jucatorActiv.IdMeci == meci.Id
                        && meci.Echipa2.Id == echipa.Id
                 select jucatorActiv.NrPuncteInscrise).Sum();
            }
            catch{}

            return scorEchipa1.ToString() + " - " + scorEchipa2.ToString(); 
        }


        public Echipa findEchipa(int id)
        {
            return echipe.FindOne(id);
        }

        public Meci findMeci(int id)
        {
            return meciuri.FindOne(id);
        }
        
        
    }
}