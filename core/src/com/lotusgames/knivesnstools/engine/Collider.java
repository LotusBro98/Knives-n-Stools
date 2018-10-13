package com.lotusgames.knivesnstools.engine;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.math.Matrix3;
import com.badlogic.gdx.math.Vector2;
import com.badlogic.gdx.math.Vector3;

import java.util.ArrayList;

public class Collider {
    public ArrayList<Vector2> colPixels;
    public Vector2 velocity;
    public Vector2 position;
    public float rotation;
    public float rotSpeed;

    public Matrix3 transform;

    public Collider(Texture texture)
    {

    }

    private void updateTransform()
    {
        transform.setToTranslation(position);
        transform.rotate(rotation);
    }
}
