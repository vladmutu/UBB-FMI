using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace Lab01
{
    public partial class Form1 : Form
    {
        private String connectionString = "Server=DESKTOP-RHOFEBS;Database=Firma-De-Imobiliare;Integrated Security=True;TrustServerCertificate=True;";
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            try
            {
                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    connection.Open();
                    MessageBox.Show("Starea conexiunii: " + connection.State.ToString());
                    DataSet dataSet = new DataSet();
                    SqlDataAdapter parentAdapter = new SqlDataAdapter("SELECT * FROM Clienti;", connection);
                    SqlDataAdapter childAdapter = new SqlDataAdapter("SELECT * FROM Contacte;", connection);
                    parentAdapter.Fill(dataSet, "Clienti");
                    childAdapter.Fill(dataSet, "Contacte");
                    BindingSource parentBS = new BindingSource();
                    BindingSource childBS = new BindingSource();
                    parentBS.DataSource = dataSet.Tables["Clienti"];
                    dataGridViewParent.DataSource = parentBS;
                    DataColumn parentPK = dataSet.Tables["Clienti"].Columns["id_client"];
                    DataColumn childFK = dataSet.Tables["Contacte"].Columns["id_client"];
                    DataRelation relation = new DataRelation("fk_parent_child", parentPK, childFK);
                    dataSet.Relations.Add(relation);
                    childBS.DataSource = parentBS;
                    childBS.DataMember = "fk_parent_child";
                    dataGridViewChild.DataSource = childBS;
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("Nu se poate realiza conexiunea\n" + ex.ToString());
            }
        }

        private void updateButton_Click(object sender, EventArgs e)
        {
            try
            {
                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    connection.Open();
                    DateTime data = this.dateTimePicker.Value;
                    string tip_contact = radioButtonEmail.Checked ? "email" : "telefon";
                    string descriere = this.textBoxDescriereContact.Text;
                    try
                    {
                        int test = dataGridViewChild.SelectedRows[0].Index;
                        if (dataGridViewChild.SelectedRows.Count > 1)
                            throw new Exception("Trebuie selectat un singur rand");
                    }
                    catch (Exception ex)
                    {
                        if (ex.ToString() == "Trebuie selectat un singur rand")
                            MessageBox.Show("Trebuie selectat un singur rand");
                        else
                            MessageBox.Show("Nu s-a selectat niciun rand");
                    }
                    int id_contact = (int)dataGridViewChild.SelectedRows[0].Cells[0].Value;
                    SqlCommand command = new SqlCommand("UPDATE Contacte SET data_contactulul=@data, tip_contact=@tip_contact, descriere_contact=@descriere WHERE id_contact=@id_contact;", connection);
                    command.Parameters.AddWithValue("@data", data);
                    command.Parameters.AddWithValue("@tip_contact", tip_contact);
                    command.Parameters.AddWithValue("@descriere", descriere);
                    command.Parameters.AddWithValue("@id_contact", id_contact);
                    command.ExecuteNonQuery();
                    DataSet dataSet = new DataSet();
                    SqlDataAdapter parentAdapter = new SqlDataAdapter("SELECT * FROM Clienti;", connection);
                    SqlDataAdapter childAdapter = new SqlDataAdapter("SELECT * FROM Contacte;", connection);
                    parentAdapter.Fill(dataSet, "Clienti");
                    childAdapter.Fill(dataSet, "Contacte");
                    BindingSource parentBS = new BindingSource();
                    BindingSource childBS = new BindingSource();
                    parentBS.DataSource = dataSet.Tables["Clienti"];
                    dataGridViewParent.DataSource = parentBS;
                    DataColumn parentPK = dataSet.Tables["Clienti"].Columns["id_client"];
                    DataColumn childFK = dataSet.Tables["Contacte"].Columns["id_client"];
                    DataRelation relation = new DataRelation("fk_parent_child", parentPK, childFK);
                    dataSet.Relations.Add(relation);
                    childBS.DataSource = parentBS;
                    childBS.DataMember = "fk_parent_child";
                    dataGridViewChild.DataSource = childBS;
                }
            }
            catch (SqlException ex)
            {
                MessageBox.Show("Nu s-a putut face update-ul");
            }
        }

        private void addButton_Click(object sender, EventArgs e)
        {
            try
            {
                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    connection.Open();
                    DateTime data = this.dateTimePicker.Value;
                    string tip_contact = radioButtonEmail.Checked ? "email" : "telefon";
                    string descriere = this.textBoxDescriereContact.Text;
                    try
                    {
                        int test = dataGridViewParent.SelectedRows[0].Index;
                        if (dataGridViewChild.SelectedRows.Count > 1)
                            throw new Exception("Trebuie selectat un singur rand");
                    }
                    catch (Exception ex)
                    {
                        if (ex.ToString() == "Trebuie selectat un singur rand")
                            MessageBox.Show("Trebuie selectat un singur rand");
                        else
                            MessageBox.Show("Nu s-a selectat niciun rand");
                    }
                    int id_client = (int)dataGridViewParent.SelectedRows[0].Cells[0].Value;
                    SqlCommand command = new SqlCommand("INSERT INTO Contacte(id_client, data_contactulul, tip_contact, descriere_contact) " +
                        "VALUES (@id_client, @data_contactului, @tip_contact, @descrierea_contactului);", connection);
                    command.Parameters.AddWithValue("@data_contactului", data);
                    command.Parameters.AddWithValue("@tip_contact", tip_contact);
                    command.Parameters.AddWithValue("@descrierea_contactului", descriere);
                    command.Parameters.AddWithValue("@id_client", id_client);
                    command.ExecuteNonQuery();
                    DataSet dataSet = new DataSet();
                    SqlDataAdapter parentAdapter = new SqlDataAdapter("SELECT * FROM Clienti;", connection);
                    SqlDataAdapter childAdapter = new SqlDataAdapter("SELECT * FROM Contacte;", connection);
                    parentAdapter.Fill(dataSet, "Clienti");
                    childAdapter.Fill(dataSet, "Contacte");
                    BindingSource parentBS = new BindingSource();
                    BindingSource childBS = new BindingSource();
                    parentBS.DataSource = dataSet.Tables["Clienti"];
                    dataGridViewParent.DataSource = parentBS;
                    DataColumn parentPK = dataSet.Tables["Clienti"].Columns["id_client"];
                    DataColumn childFK = dataSet.Tables["Contacte"].Columns["id_client"];
                    DataRelation relation = new DataRelation("fk_parent_child", parentPK, childFK);
                    dataSet.Relations.Add(relation);
                    childBS.DataSource = parentBS;
                    childBS.DataMember = "fk_parent_child";
                    dataGridViewChild.DataSource = childBS;
                }
            }
            catch (SqlException ex)
            {
                MessageBox.Show("Nu s-a putut face adaugarea\n" +ex.ToString());
            }
        }

        private void deleteButton_Click(object sender, EventArgs e)
        {
            try
            {
                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    connection.Open();
                    try
                    {
                        int test = dataGridViewChild.SelectedRows[0].Index;
                        if (dataGridViewChild.SelectedRows.Count > 1)
                            throw new Exception("Trebuie selectat un singur rand");
                    }
                    catch (Exception ex)
                    {
                        if (ex.ToString() == "Trebuie selectat un singur rand")
                            MessageBox.Show("Trebuie selectat un singur rand");
                        else
                            MessageBox.Show("Nu s-a selectat niciun rand");
                    }
                    int id_contact = (int)dataGridViewChild.SelectedRows[0].Cells[0].Value;
                    SqlCommand command = new SqlCommand("DELETE FROM Contacte WHERE id_contact=@id_contact;", connection);
                    command.Parameters.AddWithValue("@id_contact", id_contact);
                    command.ExecuteNonQuery();
                    DataSet dataSet = new DataSet();
                    SqlDataAdapter parentAdapter = new SqlDataAdapter("SELECT * FROM Clienti;", connection);
                    SqlDataAdapter childAdapter = new SqlDataAdapter("SELECT * FROM Contacte;", connection);
                    parentAdapter.Fill(dataSet, "Clienti");
                    childAdapter.Fill(dataSet, "Contacte");
                    BindingSource parentBS = new BindingSource();
                    BindingSource childBS = new BindingSource();
                    parentBS.DataSource = dataSet.Tables["Clienti"];
                    dataGridViewParent.DataSource = parentBS;
                    DataColumn parentPK = dataSet.Tables["Clienti"].Columns["id_client"];
                    DataColumn childFK = dataSet.Tables["Contacte"].Columns["id_client"];
                    DataRelation relation = new DataRelation("fk_parent_child", parentPK, childFK);
                    dataSet.Relations.Add(relation);
                    childBS.DataSource = parentBS;
                    childBS.DataMember = "fk_parent_child";
                    dataGridViewChild.DataSource = childBS;
                }
            }
            catch (SqlException ex)
            {
                MessageBox.Show("Nu s-a putut face stergerea");
            }
        }
    }
}
