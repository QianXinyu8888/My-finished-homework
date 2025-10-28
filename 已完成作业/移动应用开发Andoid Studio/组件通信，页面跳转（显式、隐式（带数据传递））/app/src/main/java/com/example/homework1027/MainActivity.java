package com.example.homework1027;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.Spinner;
import android.widget.TextView;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });
        Button button_show= findViewById(R.id.button_show);
        Button button_unshow=findViewById(R.id.button_unshow);

        EditText edittext_id = findViewById(R.id.edittext_id);
        EditText edittext_name = findViewById(R.id.edittext_name);
        RadioGroup radiogroup_sex = findViewById(R.id.radiogroup_sex);
        Spinner spinner_college = findViewById(R.id.spinner_college);
        EditText edittext_major = findViewById(R.id.edittext_major);
        EditText edittext_class = findViewById(R.id.edittext_class);
        button_show.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent =new Intent(MainActivity.this, MainActivity2.class);
                startActivity(intent);
            }
        });

        button_unshow.setOnClickListener(new View.OnClickListener() {
            @Override

            public void onClick(View v) {
                String idReadytoSend = edittext_id.getText().toString();//定义一个临时变量用于获取edittext中的文本
                String nameReadytoSend = edittext_name.getText().toString();
                int sexReadytoSend = radiogroup_sex.getCheckedRadioButtonId();
                String collegeReadytoSend = (String) spinner_college.getSelectedItem();
                String majorReadytoSend = edittext_major.getText().toString();
                String classReadytoSend = edittext_class.getText().toString();

                Intent intent = new Intent();
                intent.putExtra("id", idReadytoSend);//第一个参数是键名，需和接收方写的键名保持一致
                intent.putExtra("name", nameReadytoSend);
                intent.putExtra("sex", sexReadytoSend);
                intent.putExtra("college", collegeReadytoSend);
                intent.putExtra("major", majorReadytoSend);
                intent.putExtra("class", classReadytoSend);
                intent.setAction("com.example.homework1027.action.jumpToMainActivity2");
                startActivity(intent);
            }
        });




    }





}