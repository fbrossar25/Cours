import { Country } from './../shared/models/country';
import { Component, OnInit } from '@angular/core';
import { ActivatedRoute } from '@angular/router';
import { RestCountriesService } from './../shared/services/rest-countries.service';

@Component({
  selector: 'app-country',
  templateUrl: './country.component.html',
  styleUrls: ['./country.component.scss']
})
export class CountryComponent implements OnInit {

  country: Country;
  alphaCode = '';

  constructor(private route: ActivatedRoute, private countriesService: RestCountriesService) {  }

  ngOnInit() {
    this.alphaCode = this.route.snapshot.paramMap.get('code');
    console.log(`Affichage du pays de code '${this.alphaCode}'`);
    this.countriesService.getByAlphaCode(this.alphaCode).subscribe(
      country => this.country = country,
      error => {
        if (error.status === 404 && error.statusText === 'OK') {
            console.log(`Pas de pays de code '${this.alphaCode}'`);
        } else {
          console.log(`Une erreur est survenue pour le pays de code '${this.alphaCode}' : ${error.message}`);
          console.error(error);
        }
        this.country = null;
      }
    );
  }

}
