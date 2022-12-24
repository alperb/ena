#include <string>
#include <vector>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexBufferLayout.h"

enum BUFFER_TYPE {
    INDEX_BUFFER,
    VERTEX_BUFFER,
    TEXCOORD_BUFFER,
    NORMAL_BUFFER,
};

struct MeshEntry {
    MeshEntry() {
        numIndices = 0;
        baseVertex = 0;
        baseIndex = 0;
        materialIndex = 0;
    };

    unsigned int numIndices;
    unsigned int baseVertex;
    unsigned int baseIndex;
    unsigned int materialIndex;
};

class Mesh {
public:
    Mesh(const std::string& fileName);
    ~Mesh();
    void loadMesh();
    void draw();
private:
    void reserveSpace();
    void prepareMeshes(const aiScene* scene);
    void initSingleMesh(const aiMesh* mesh);


    std::string fileName;
    std::vector<MeshEntry> meshes;

    unsigned int numVertices;
    unsigned int numIndices;

    VertexArray* vao;
    IndexBuffer* ibo;

    std::vector<float> positions;
    std::vector<float> texCoords;
    std::vector<float> normals;
    std::vector<unsigned int> indices;
};