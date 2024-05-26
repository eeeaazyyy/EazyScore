package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
	"os"
)

func main() {

	url := "https://v3.football.api-sports.io/standings?league=140&season=2023"
	method := "GET"

	apiKey := os.Getenv("API_SPORT")
	fmt.Println(apiKey)

	client := &http.Client{}
	req, err := http.NewRequest(method, url, nil)

	if err != nil {
		fmt.Println(err)
		return
	}
	req.Header.Add("x-rapidapi-key", apiKey)
	req.Header.Add("x-rapidapi-host", "v3.football.api-sports.io")

	res, err := client.Do(req)
	if err != nil {
		fmt.Println(err)
		return
	}
	defer res.Body.Close()

	body, err := ioutil.ReadAll(res.Body)
	if err != nil {
		fmt.Println(err)
		return
	}
	fmt.Println(string(body))
}
