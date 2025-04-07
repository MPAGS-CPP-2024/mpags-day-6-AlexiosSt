//! Unit Tests for MPAGSCipher processCommandLine interface
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "ProcessCommandLine.hpp"

TEST_CASE("Help found correctly", "[commandline]")
{
    ProgramSettings settings{false, false, "", "", {}, {}, CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher", "--help"};
    REQUIRE_NOTHROW(processCommandLine(cmdLine, settings));
}

TEST_CASE("Version found correctly", "[commandline]")
{
    ProgramSettings settings{false, false, "", "", {}, {}, CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher", "--version"};
    REQUIRE_NOTHROW(processCommandLine(cmdLine, settings));
}

TEST_CASE("Encrypt mode activated")
{
    ProgramSettings settings{false, false, "", "", {}, {}, CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher", "--encrypt"};
    REQUIRE_NOTHROW(processCommandLine(cmdLine, settings));
}

TEST_CASE("Decrypt mode activated")
{
    ProgramSettings settings{false, false, "", "", {}, {}, CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher", "--decrypt"};
    REQUIRE_NOTHROW(processCommandLine(cmdLine, settings));
}

TEST_CASE("Key entered with no key specified")
{
    ProgramSettings settings{false, false, "", "", {}, {}, CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher", "-k"};
    REQUIRE_THROWS_AS(processCommandLine(cmdLine, settings), MissingArgument);
}

TEST_CASE("Key entered with key specified")
{
    ProgramSettings settings{false, false, "", "", {}, {}, CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher", "-k", "4"};
    REQUIRE_NOTHROW(processCommandLine(cmdLine, settings));
}

TEST_CASE("Input file declared without using input file")
{
    ProgramSettings settings{false, false, "", "", {}, {}, CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher", "-i"};
    REQUIRE_THROWS_AS(processCommandLine(cmdLine, settings), MissingArgument);
}

TEST_CASE("Input file declared")
{
    ProgramSettings settings{false, false, "", "", {}, {}, CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher", "-i", "input.txt"};
    REQUIRE_NOTHROW(processCommandLine(cmdLine, settings));
    REQUIRE(settings.inputFile == "input.txt");
}

TEST_CASE("Cipher caesar declared")
{
    ProgramSettings settings{false, false, "", "", {}, {}, CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher", "-c", "caesar"};
    REQUIRE_NOTHROW(processCommandLine(cmdLine, settings));
    REQUIRE(settings.cipherType.size()==1);
    REQUIRE(settings.cipherType[0] == CipherType::Caesar);
}

TEST_CASE("Cipher playfair declared")
{
    ProgramSettings settings{false, false, "", "", {}, {}, CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher", "-c", "playfair"};
    REQUIRE_NOTHROW(processCommandLine(cmdLine, settings));
    REQUIRE(settings.cipherType.size()==1);
    REQUIRE(settings.cipherType[0] == CipherType::Playfair);
}

TEST_CASE("Cipher vigenere declared")
{
    ProgramSettings settings{false, false, "", "", {}, {}, CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher", "-c", "vigenere"};
    REQUIRE_NOTHROW(processCommandLine(cmdLine, settings));
    REQUIRE(settings.cipherType.size()==1);
    REQUIRE(settings.cipherType[0] == CipherType::Vigenere);
}

TEST_CASE("Cipher declared with no cipher specified")
{
    ProgramSettings settings{false, false, "", "", {}, {}, CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher", "-c"};
    REQUIRE_THROWS_AS(processCommandLine(cmdLine, settings), MissingArgument);
}

TEST_CASE("Cipher declared with unknown cipher")
{
    ProgramSettings settings{false, false, "", "", {}, {}, CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher", "-c", "unknown"};
    REQUIRE_THROWS_AS(processCommandLine(cmdLine, settings), UnknownArgument);
}

TEST_CASE("Output file declared without using output file")
{
    ProgramSettings settings{false, false, "", "", {}, {}, CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher", "-o"};
    REQUIRE_THROWS_AS(processCommandLine(cmdLine, settings), MissingArgument);
}

TEST_CASE("Output file declared")
{
    ProgramSettings settings{false, false, "", "", {}, {}, CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher", "-o", "output.txt"};
    REQUIRE_NOTHROW(processCommandLine(cmdLine, settings));
    REQUIRE(settings.outputFile == "output.txt");
}

TEST_CASE("Multi-cipher declared")
{
    ProgramSettings settings{false, false, "", "", {}, {}, CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher", "--multi-cipher", "3"};
    REQUIRE_THROWS_AS(processCommandLine(cmdLine, settings), InconsistentArguments);
}

TEST_CASE("Multi-cipher declared with no number")
{
    ProgramSettings settings{false, false, "", "", {}, {}, CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher", "--multi-cipher"};
    REQUIRE_THROWS_AS(processCommandLine(cmdLine, settings), MissingArgument);
}

TEST_CASE("Multi-cipher declared with non-integer")
{
    ProgramSettings settings{false, false, "", "", {}, {}, CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher", "--multi-cipher", "notanumber"};
    REQUIRE_THROWS_AS(processCommandLine(cmdLine, settings), InvalidArgument);
}
TEST_CASE("Multi-cipher declared with too large number")
{
    ProgramSettings settings{false, false, "", "", {}, {}, CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher", "--multi-cipher", "18446744073709551616"};
    REQUIRE_THROWS_AS(processCommandLine(cmdLine, settings), InvalidArgument);
}