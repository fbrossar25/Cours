import { Component, OnInit, OnChanges, SimpleChanges } from '@angular/core';
import { ActivatedRoute, Router, NavigationEnd } from '@angular/router';
import { RestCountriesService } from './../shared/services/rest-countries.service';
import { CountryShort } from '../shared/models/country-short';

@Component({
  selector: 'app-country-list',
  templateUrl: './country-list.component.html',
  styleUrls: ['./country-list.component.scss']
})
export class CountryListComponent implements OnInit {

  countries: CountryShort[];
  property = null;
  value = null;

  constructor(private router: Router, private route: ActivatedRoute, private countriesService: RestCountriesService) { }

  ngOnInit() {
    this.router.events.subscribe(event => {
      if (event instanceof NavigationEnd && !event.url.endsWith(`list/${this.property}/${this.value}`)) {
        this.update();
      }
    });
    this.update();
  }

  update() {
    this.property = this.route.snapshot.paramMap.get('property');
    this.value = this.route.snapshot.paramMap.get('value');
    this.countriesService
      .getNamesByProperty(this.property , this.value)
      .subscribe(
        countries => {
          if (Array.isArray(countries)) {
            // Plusieurs résultats
            this.countries = countries;
          } else {
            // Un seul résultats
            this.countries = [countries];
          }
        },
        error => {
          if (error.status === 404 && error.statusText === 'OK') {
            console.log(`Pas de résultats pour ${this.property }=${this.value}`);
          } else {
            console.log(`Une erreur est survenue pour ${this.property }=${this.value} : ${error.message}`);
            console.error(error);
          }
          this.countries = [];
        }
      );
  }

}
