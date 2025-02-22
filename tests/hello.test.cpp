#include <gtest/gtest.h>

// Função a ser testada
int soma(int a, int b) {
    return a + b;
}

// Teste unitário
TEST(SomaTest, TestaSoma) {
    EXPECT_EQ(soma(2, 3), 5);
    EXPECT_EQ(soma(-1, 1), 0);
}

// Função principal do Google Test
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
