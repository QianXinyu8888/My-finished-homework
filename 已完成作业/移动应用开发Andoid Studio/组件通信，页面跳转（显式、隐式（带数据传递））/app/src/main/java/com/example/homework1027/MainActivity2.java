package com.example.homework1027;

import android.content.Intent;
import android.os.Bundle;
import android.widget.Spinner;
import android.widget.TextView;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class MainActivity2 extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main2);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });
        TextView textView_id2 = findViewById(R.id.textview_id2);
        TextView textView_name2 = findViewById(R.id.textview_name2);
        TextView textView_sex2 = findViewById(R.id.textview_sex2);
        TextView textView_college2 = findViewById(R.id.textview_college2);
        TextView textView_major2 = findViewById(R.id.textview_major2);
        TextView textView_class2 = findViewById(R.id.textview_class2);

        Intent receivedIntent = getIntent();//接受发送方发来的信息
        if (receivedIntent != null) {
            String receivedID = receivedIntent.getStringExtra("id");
            textView_id2.setText(receivedID);
            String receivedName = receivedIntent.getStringExtra("name");
            textView_name2.setText(receivedName);
            String receivedSex = receivedIntent.getStringExtra("sex");
            textView_sex2.setText(receivedSex);
            String receivedCollege = receivedIntent.getStringExtra("college");
            textView_college2.setText(receivedCollege);
            String receivedMajor= receivedIntent.getStringExtra("major");
            textView_major2.setText(receivedMajor);
            String receivedClass = receivedIntent.getStringExtra("class");
            textView_class2.setText(receivedClass);
        }
    }
}