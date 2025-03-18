using Microsoft.Data.SqlClient;

namespace Seminar1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.BackgroundColor = ConsoleColor.Black;
            Console.Clear();
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.WriteLine("Hello, World of ADO.NET");
            try
            {
                string connectionString = @"Server=DESKTOP-RHOFEBS;Database=Seminar1SGBD;Integrated Security=true;TrustServerCertificate=true";
                using(SqlConnection connection = new SqlConnection(connectionString))
                {
                    Console.WriteLine("Starea conexiunii: {0}", connection.State);
                    connection.Open();
                    Console.WriteLine("Starea conexiunii: {0}", connection.State);
                    SqlCommand insertCommand = new SqlCommand("INSERT INTO Produse (nume, pret, producator) VALUES" + 
                        "(@nume1, @pret1, @producator1), (@nume2, @pret2, @producator2);", connection);
                    insertCommand.Parameters.AddWithValue("@nume1", "laptop");
                    insertCommand.Parameters.AddWithValue("@pret1", 3000);
                    insertCommand.Parameters.AddWithValue("@producator1", "Asus");
                    insertCommand.Parameters.AddWithValue("@nume2", "AirFryer");
                    insertCommand.Parameters.AddWithValue("@pret2", 1600);
                    insertCommand.Parameters.AddWithValue("@producator2", "Bosch");
                    int insertRowCount = insertCommand.ExecuteNonQuery();
                    Console.WriteLine("Insert Row Count: {0}", insertRowCount);
                    //citire date
                    SqlCommand selectCommand = new SqlCommand("SELECT nume, pret, producator FROM Produse;", connection);
                    SqlDataReader reader = selectCommand.ExecuteReader();
                    if(reader.HasRows)
                    {
                        while (reader.Read())
                        {
                            Console.WriteLine("{0}\t{1}\t{2}", reader.GetString(0), reader.GetFloat(1), reader.GetString(2));
                        }
                    }
                    reader.Close();
                    //actualizarea datelor
                    SqlCommand updateCommand = new SqlCommand("UPDATE Produse SET pret=@pretnou WHERE nume = @nume;", connection);
                    updateCommand.Parameters.AddWithValue("@pretnou", 1200);
                    updateCommand.Parameters.AddWithValue("@nume", "AirFryer");
                    //se poate apela metoda ExecuteNonQuery pe obiectul de tip SqlCommand si fara a stoca numarul de inregistrari afectate de comanda
                    Console.WriteLine("Actualizare date");
                    updateCommand.ExecuteNonQuery();
                    Console.WriteLine("Stergere date");
                    SqlCommand deleteCommand = new SqlCommand("DELETE FROM Produse WHERE nume = @nume;", connection);
                    deleteCommand.Parameters.AddWithValue("@nume", "laptop");
                    int deleteRowCount = deleteCommand.ExecuteNonQuery();
                    Console.WriteLine("Delete Row Count: {0}", deleteRowCount);
                    //citirea datelor dupa actualizare si stergere
                    Console.WriteLine("Citirea datelor dupa actualizare si stergere");
                    reader = selectCommand.ExecuteReader();
                    if (reader.HasRows)
                    {
                        while (reader.Read())
                        {
                            Console.WriteLine("{0}\t{1}\t{2}", reader.GetString(0), reader.GetFloat(1), reader.GetString(2));
                        }
                    }
                    reader.Close();
                }
            }
            catch (Exception ex)
            {
                Console.ForegroundColor = ConsoleColor.DarkRed;
                Console.WriteLine(ex.ToString());
            }
        }
    }
}
