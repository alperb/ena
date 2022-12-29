#include <iostream>
#include <fstream>
#include <sstream>

#include "Mesh.h"


#define ASSIMP_LOAD_FLAGS (aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs | aiProcess_JoinIdenticalVertices)

Mesh::Mesh(const std::string& fileName): fileName(fileName){
    loadMesh();
}

Mesh::~Mesh(){
}

void Mesh::draw(){
    vao->bind();
    for(unsigned int i = 0; i < meshes.size(); i++) {
        const unsigned int materialIndex = meshes[i].materialIndex;

        glDrawElementsBaseVertex(GL_TRIANGLES,
            meshes[i].numIndices,
            GL_UNSIGNED_INT,
            (void*)(sizeof(unsigned int) * meshes[i].baseIndex),
            meshes[i].baseVertex);
    }

    vao->unbind();
}

void Mesh::loadMesh(){
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(fileName, ASSIMP_LOAD_FLAGS);

    if(!scene) {
        std::cout << "Error loading mesh: " << fileName << std::endl;
        return;
    }

    meshes.resize(scene->mNumMeshes);

    prepareMeshes(scene);

    reserveSpace();

    for(unsigned int i = 0; i < scene->mNumMeshes; i++) {
        const aiMesh* mesh = scene->mMeshes[i];
        initSingleMesh(mesh);
    }

    vao = new VertexArray();

    
    VertexBuffer posBuffer(positions.data(), positions.size() * sizeof(float));
    VertexBufferLayout posLayout;
    posLayout.push<float>(3);
    posLayout.push<float>(3);
    posLayout.push<float>(2);

    vao->addBuffer(posBuffer, posLayout);

    ibo = new IndexBuffer(indices.data(), indices.size());
}

void Mesh::initSingleMesh(const aiMesh* mesh){
    const aiVector3D Zero3D(0.0f, 0.0f, 0.0f);

    for(unsigned int i = 0; i < mesh->mNumVertices; i++) {
        const aiVector3D* pPos = &(mesh->mVertices[i]);
        const aiVector3D* pNormal = &(mesh->mNormals[i]);
        const aiVector3D* pTexCoord = mesh->HasTextureCoords(0) ? &(mesh->mTextureCoords[0][i]) : &Zero3D;

        positions.push_back(pPos->x);
        positions.push_back(pPos->y);
        positions.push_back(pPos->z);

        onlyPositions.push_back(pPos->x);
        onlyPositions.push_back(pPos->y);
        onlyPositions.push_back(pPos->z);
        
        positions.push_back(pNormal->x);
        positions.push_back(pNormal->y);
        positions.push_back(pNormal->z);

        positions.push_back(pTexCoord->x);
        positions.push_back(pTexCoord->y);

    }

    for(unsigned int i = 0; i < mesh->mNumFaces; i++) {
        const aiFace& face = mesh->mFaces[i];
        indices.push_back(face.mIndices[0]);
        indices.push_back(face.mIndices[1]);
        indices.push_back(face.mIndices[2]);
    }
}

void Mesh::prepareMeshes(const aiScene* scene){
    for(unsigned int i = 0; i < scene->mNumMeshes; i++) {
        const aiMesh* mesh = scene->mMeshes[i];
        meshes[i].numIndices = mesh->mNumFaces * 3;
        meshes[i].baseVertex = numVertices;
        meshes[i].baseIndex = numIndices;
        meshes[i].materialIndex = mesh->mMaterialIndex;

        numVertices += mesh->mNumVertices;
        numIndices += meshes[i].numIndices;
    }
}

void Mesh::reserveSpace(){
    positions.reserve(numVertices);
    texCoords.reserve(numVertices);
    normals.reserve(numVertices);
    indices.reserve(numIndices);
}

std::vector<float> Mesh::getPositions() const {
    return onlyPositions;
}