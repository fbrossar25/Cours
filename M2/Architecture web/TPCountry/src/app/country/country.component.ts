import { Country } from './../../models/country';
import { Component, OnInit, Input } from '@angular/core';
import { ActivatedRoute } from '@angular/router';
import { RestCountriesService } from 'src/services/rest-countries.service';

@Component({
  selector: 'app-country',
  templateUrl: './country.component.html',
  styleUrls: ['./country.component.scss']
})
export class CountryComponent implements OnInit {

  country: Country;

  constructor(private route: ActivatedRoute, private countriesService: RestCountriesService) { }

  ngOnInit() {
    const countryName = this.route.snapshot.paramMap.get('country');
    this.countriesService.getByName(countryName).subscribe(countries => {
      this.country = countries[0];
      if (this.country == null || this.country === undefined) {
        console.log(`Le pays '${countryName}' n\'as pas été trouvé`);
      }
    });
  }

}
