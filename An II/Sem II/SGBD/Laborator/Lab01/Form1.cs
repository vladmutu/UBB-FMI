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
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            string connectionString = "Server=DESKTOP-RHOFEBS;Database=Firma-De-Imobiliare;Integrated Security=True;TrustServerCertificate=True;";
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
    }
}
