#include "gtest/gtest.h"
#include "Vector.hpp"

class VectorTemplateTests : public ::testing::Test {
protected:
    Vector<int> vector{};
    int dato{};
};

TEST_F(VectorTemplateTests, Alta) {
    vector.alta(1);
    EXPECT_EQ(vector[0], 1);

    vector.alta(2);
    EXPECT_EQ(vector[1], 2);
}

TEST_F(VectorTemplateTests, AltaIndice) {
    vector.alta(1, 0);
    EXPECT_EQ(vector[0], 1);

    vector.alta(2, 0);
    EXPECT_EQ(vector[0], 2);
}

TEST_F(VectorTemplateTests, AltaIndiceManejaIndiceMayorACantidadDeDatos) {
    EXPECT_THROW(vector.alta(1, 1), VectorException);
}


TEST_F(VectorTemplateTests, Baja) {
    vector.alta(1);

    dato = vector.baja();
    EXPECT_EQ(dato, 1);
}

TEST_F(VectorTemplateTests, BajaManejaVectorVacio) {
    EXPECT_THROW(vector.baja(), VectorException);
}

TEST_F(VectorTemplateTests, BajaIndice) {
    vector.alta(1);
    vector.alta(2);

    dato = vector.baja(0);
    EXPECT_EQ(dato, 1);

    dato = vector.baja(0);
    EXPECT_EQ(dato, 2);
}

TEST_F(VectorTemplateTests, BajaIndiceManejaVectorVacio) {
    EXPECT_THROW(vector.baja(0), VectorException);
}

TEST_F(VectorTemplateTests, BajaIndiceManejaIndiceMayorOIgualACantidadDeDatos) {
    vector.alta(1);

    EXPECT_THROW(vector.baja(1), VectorException);
}

TEST_F(VectorTemplateTests, Vacio) {
    EXPECT_TRUE(vector.vacio());

    vector.alta(1);
    EXPECT_FALSE(vector.vacio());

    vector.baja();
    EXPECT_TRUE(vector.vacio());
}

TEST_F(VectorTemplateTests, Tamanio) {
    EXPECT_EQ(vector.tamanio(), 0);

    vector.alta(1);
    vector.alta(2);
    vector.alta(3);
    EXPECT_EQ(vector.tamanio(), 3);

    vector.baja();
    EXPECT_EQ(vector.tamanio(), 2);
}

TEST_F(VectorTemplateTests, OperadorAcceso) {
    vector.alta(1);
    vector.alta(2, 0);
    vector.alta(3);
    dato = vector.baja(0);

    EXPECT_EQ(vector[1], 3);
    EXPECT_EQ(dato, 2);
}

TEST_F(VectorTemplateTests, OperadorAccesoManejaVectorVacio) {
    EXPECT_THROW(vector[0], VectorException);
}

TEST_F(VectorTemplateTests, OperadorAccesoManejaIndiceMayorOIgualACantidadDeDatos) {
    vector.alta(1);

    EXPECT_THROW(vector[1], VectorException);
}