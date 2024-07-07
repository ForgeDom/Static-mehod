#include <iostream>
#include <cstring>

using namespace std;

struct VideoStore {
private:
    char movieTitle[50];
    char director[50];
    char genre[50];
    int popularityRating;
    double discPrice;
public:
    static const int maxRecords = 50;

    VideoStore(const char* title = "", const char* dir = "", const char* gen = "", int rating = 0, double price = 0.0) {
        strncpy_s(movieTitle, title, sizeof(movieTitle) - 1);
        strncpy_s(director, dir, sizeof(director) - 1);
        strncpy_s(genre, gen, sizeof(genre) - 1);
        popularityRating = rating;
        discPrice = price;
    }

    static void addRecord(VideoStore store[], int& count, const VideoStore& record) {
        if (count < maxRecords) {
            store[count] = record;
            ++count;
            cout << "Record added successfully.\n";
        }
        else {
            cout << "Video store is full!\n";
        }
    }

    static void showRecords(const VideoStore store[], int count) {
        if (count == 0) {
            cout << "No records found.\n";
            return;
        }
        for (int i = 0; i < count; ++i) {
            cout << "Movie name: " << store[i].movieTitle << "\n"
                << "Director: " << store[i].director << "\n"
                << "Genre: " << store[i].genre << "\n"
                << "Popularity rating: " << store[i].popularityRating << "\n"
                << "Disc price: " << store[i].discPrice << " $\n"
                << "---------------------------\n";
        }
    }

    static void searchByTitle(const VideoStore store[], int count, const char* title) {
        bool found = false;
        for (int i = 0; i < count; ++i) {
            if (strcmp(store[i].movieTitle, title) == 0) {
                cout << "Movie name: " << store[i].movieTitle << "\n"
                    << "Director: " << store[i].director << "\n"
                    << "Genre: " << store[i].genre << "\n"
                    << "Popularity rating: " << store[i].popularityRating << "\n"
                    << "Disc price: " << store[i].discPrice << " $\n"
                    << "---------------------------\n";
                found = true;
            }
        }
        if (!found) {
            cout << "Movie with title \"" << title << "\" not found.\n";
        }
    }

    static void searchByGenre(const VideoStore store[], int count, const char* genre) {
        bool found = false;
        for (int i = 0; i < count; ++i) {
            if (strcmp(store[i].genre, genre) == 0) {
                cout << "Movie name: " << store[i].movieTitle << "\n"
                    << "Director: " << store[i].director << "\n"
                    << "Genre: " << store[i].genre << "\n"
                    << "Popularity rating: " << store[i].popularityRating << "\n"
                    << "Disc price: " << store[i].discPrice << " $\n"
                    << "---------------------------\n";
                found = true;
            }
        }
        if (!found) {
            cout << "No movies found in genre \"" << genre << "\".\n";
        }
    }

    static void searchByDirector(const VideoStore store[], int count, const char* director) {
        bool found = false;
        for (int i = 0; i < count; ++i) {
            if (strcmp(store[i].director, director) == 0) {
                cout << "Movie name: " << store[i].movieTitle << "\n"
                    << "Director: " << store[i].director << "\n"
                    << "Genre: " << store[i].genre << "\n"
                    << "Popularity rating: " << store[i].popularityRating << "\n"
                    << "Disc price: " << store[i].discPrice << " $\n"
                    << "---------------------------\n";
                found = true;
            }
        }
        if (!found) {
            cout << "No movies found by director \"" << director << "\".\n";
        }
    }

    static void mostPopularInGenre(const VideoStore store[], int count, const char* genre) {
        VideoStore mostPopular;
        bool found = false;
        for (int i = 0; i < count; ++i) {
            if (strcmp(store[i].genre, genre) == 0 && store[i].popularityRating > mostPopular.popularityRating) {
                mostPopular = store[i];
                found = true;
            }
        }
        if (found) {
            cout << "Most popular movie in genre \"" << genre << "\":\n";
            cout << "Movie name: " << mostPopular.movieTitle << "\n"
                << "Director: " << mostPopular.director << "\n"
                << "Genre: " << mostPopular.genre << "\n"
                << "Popularity rating: " << mostPopular.popularityRating << "\n"
                << "Disc price: " << mostPopular.discPrice << " $\n";
        }
        else {
            cout << "No movies found in genre \"" << genre << "\".\n";
        }
    }
};

void displayMenu() {
    cout << "\n========== Video Store ===========================\n";
    cout << "1. Add a movie record\n";
    cout << "2. Show all movie records\n";
    cout << "3. Search movie by title\n";
    cout << "4. Search movies by genre\n";
    cout << "5. Search movies by director\n";
    cout << "6. Find most popular movie in a genre\n";
    cout << "0. Exit\n";
    cout << "===================================================\n";
    cout << "Enter your choice: ";
}

int main() {
    VideoStore videoStore[VideoStore::maxRecords];
    int count = 0;

    int choice;
    do {
        displayMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            char title[50], director[50], genre[50];
            int rating;
            double price;

            cout << "Enter movie title: ";
            cin.getline(title, sizeof(title));

            cout << "Enter director: ";
            cin.getline(director, sizeof(director));

            cout << "Enter genre: ";
            cin.getline(genre, sizeof(genre));

            cout << "Enter popularity rating (0 - 10.0): ";
            cin >> rating;

            cout << "Enter disc price: ";
            cin >> price;

            VideoStore::addRecord(videoStore, count, VideoStore(title, director, genre, rating, price));
            break;
        }
        case 2:
            cout << "\nShowing all movie records:" << endl;;
            VideoStore::showRecords(videoStore, count);
            break;
        case 3: {
            char title[50];
            cout << "Enter movie title to search: ";
            cin.getline(title, sizeof(title));
            VideoStore::searchByTitle(videoStore, count, title);
            break;
        }
        case 4: {
            char genre[50];
            cout << "Enter genre to search: ";
            cin.getline(genre, sizeof(genre));
            VideoStore::searchByGenre(videoStore, count, genre);
            break;
        }
        case 5: {
            char director[50];
            cout << "Enter director to search: ";
            cin.getline(director, sizeof(director));
            VideoStore::searchByDirector(videoStore, count, director);
            break;
        }
        case 6: {
            char genre[50];
            cout << "Enter genre to find most popular movie: ";
            cin.getline(genre, sizeof(genre));
            VideoStore::mostPopularInGenre(videoStore, count, genre);
            break;
        }
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. " << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}
