namespace Lab01
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.dataGridViewParent = new System.Windows.Forms.DataGridView();
            this.dataGridViewChild = new System.Windows.Forms.DataGridView();
            this.textBoxDescriereContact = new System.Windows.Forms.TextBox();
            this.labelDataContact = new System.Windows.Forms.Label();
            this.dateTimePicker1 = new System.Windows.Forms.DateTimePicker();
            this.labelTipContact = new System.Windows.Forms.Label();
            this.labelDescriereContact = new System.Windows.Forms.Label();
            this.radioButtonEmail = new System.Windows.Forms.RadioButton();
            this.radioButtonTelefon = new System.Windows.Forms.RadioButton();
            this.updateButton = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewParent)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewChild)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGridViewParent
            // 
            this.dataGridViewParent.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewParent.Location = new System.Drawing.Point(12, 12);
            this.dataGridViewParent.Name = "dataGridViewParent";
            this.dataGridViewParent.Size = new System.Drawing.Size(731, 368);
            this.dataGridViewParent.TabIndex = 0;
            // 
            // dataGridViewChild
            // 
            this.dataGridViewChild.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewChild.Location = new System.Drawing.Point(12, 386);
            this.dataGridViewChild.Name = "dataGridViewChild";
            this.dataGridViewChild.Size = new System.Drawing.Size(731, 368);
            this.dataGridViewChild.TabIndex = 1;
            // 
            // textBoxDescriereContact
            // 
            this.textBoxDescriereContact.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBoxDescriereContact.Location = new System.Drawing.Point(899, 280);
            this.textBoxDescriereContact.Multiline = true;
            this.textBoxDescriereContact.Name = "textBoxDescriereContact";
            this.textBoxDescriereContact.Size = new System.Drawing.Size(280, 44);
            this.textBoxDescriereContact.TabIndex = 5;
            // 
            // labelDataContact
            // 
            this.labelDataContact.AutoSize = true;
            this.labelDataContact.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelDataContact.Location = new System.Drawing.Point(895, 32);
            this.labelDataContact.Name = "labelDataContact";
            this.labelDataContact.Size = new System.Drawing.Size(237, 24);
            this.labelDataContact.TabIndex = 6;
            this.labelDataContact.Text = "Introduceti data contactului:";
            // 
            // dateTimePicker1
            // 
            this.dateTimePicker1.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.dateTimePicker1.Location = new System.Drawing.Point(890, 73);
            this.dateTimePicker1.Name = "dateTimePicker1";
            this.dateTimePicker1.Size = new System.Drawing.Size(320, 29);
            this.dateTimePicker1.TabIndex = 7;
            // 
            // labelTipContact
            // 
            this.labelTipContact.AutoSize = true;
            this.labelTipContact.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelTipContact.Location = new System.Drawing.Point(895, 138);
            this.labelTipContact.Name = "labelTipContact";
            this.labelTipContact.Size = new System.Drawing.Size(236, 24);
            this.labelTipContact.TabIndex = 8;
            this.labelTipContact.Text = "Introduceti tipul contactului:";
            // 
            // labelDescriereContact
            // 
            this.labelDescriereContact.AutoSize = true;
            this.labelDescriereContact.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelDescriereContact.Location = new System.Drawing.Point(895, 242);
            this.labelDescriereContact.Name = "labelDescriereContact";
            this.labelDescriereContact.Size = new System.Drawing.Size(291, 24);
            this.labelDescriereContact.TabIndex = 9;
            this.labelDescriereContact.Text = "Introduceti descrierea contactului:";
            // 
            // radioButtonEmail
            // 
            this.radioButtonEmail.AutoSize = true;
            this.radioButtonEmail.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.radioButtonEmail.Location = new System.Drawing.Point(899, 165);
            this.radioButtonEmail.Name = "radioButtonEmail";
            this.radioButtonEmail.Size = new System.Drawing.Size(73, 28);
            this.radioButtonEmail.TabIndex = 10;
            this.radioButtonEmail.TabStop = true;
            this.radioButtonEmail.Tag = "tip_contact";
            this.radioButtonEmail.Text = "email";
            this.radioButtonEmail.UseVisualStyleBackColor = true;
            // 
            // radioButtonTelefon
            // 
            this.radioButtonTelefon.AutoSize = true;
            this.radioButtonTelefon.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.radioButtonTelefon.Location = new System.Drawing.Point(899, 199);
            this.radioButtonTelefon.Name = "radioButtonTelefon";
            this.radioButtonTelefon.Size = new System.Drawing.Size(84, 28);
            this.radioButtonTelefon.TabIndex = 11;
            this.radioButtonTelefon.TabStop = true;
            this.radioButtonTelefon.Tag = "tip_contact";
            this.radioButtonTelefon.Text = "telefon";
            this.radioButtonTelefon.UseVisualStyleBackColor = true;
            // 
            // updateButton
            // 
            this.updateButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.updateButton.Location = new System.Drawing.Point(937, 359);
            this.updateButton.Name = "updateButton";
            this.updateButton.Size = new System.Drawing.Size(204, 76);
            this.updateButton.TabIndex = 12;
            this.updateButton.Text = "Update";
            this.updateButton.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1489, 769);
            this.Controls.Add(this.updateButton);
            this.Controls.Add(this.radioButtonTelefon);
            this.Controls.Add(this.radioButtonEmail);
            this.Controls.Add(this.labelDescriereContact);
            this.Controls.Add(this.labelTipContact);
            this.Controls.Add(this.dateTimePicker1);
            this.Controls.Add(this.labelDataContact);
            this.Controls.Add(this.textBoxDescriereContact);
            this.Controls.Add(this.dataGridViewChild);
            this.Controls.Add(this.dataGridViewParent);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewParent)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewChild)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridViewParent;
        private System.Windows.Forms.DataGridView dataGridViewChild;
        private System.Windows.Forms.TextBox textBoxDescriereContact;
        private System.Windows.Forms.Label labelDataContact;
        private System.Windows.Forms.DateTimePicker dateTimePicker1;
        private System.Windows.Forms.Label labelTipContact;
        private System.Windows.Forms.Label labelDescriereContact;
        private System.Windows.Forms.RadioButton radioButtonEmail;
        private System.Windows.Forms.RadioButton radioButtonTelefon;
        private System.Windows.Forms.Button updateButton;
    }
}

